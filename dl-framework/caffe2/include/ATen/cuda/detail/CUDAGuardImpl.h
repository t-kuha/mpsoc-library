#pragma once

#include <c10/impl/DeviceGuardImplInterface.h>
#include <c10/macros/Macros.h>

#include <ATen/cuda/Exceptions.h>
#include <ATen/cuda/CUDAStream.h>

#include <cuda_runtime_api.h>

namespace at {
namespace cuda {
namespace impl {

struct CUDAGuardImpl final : public c10::impl::DeviceGuardImplInterface {
  static constexpr DeviceType static_type = DeviceType::CUDA;
  CUDAGuardImpl() {}
  CUDAGuardImpl(DeviceType t) {
    AT_ASSERT(t == DeviceType::CUDA);
  }
  DeviceType type() const override {
    return DeviceType::CUDA;
  }
  Device exchangeDevice(Device d) const override {
    AT_ASSERT(d.type() == DeviceType::CUDA);
    Device old_device = getDevice();
    if (old_device.index() != d.index()) {
      AT_CUDA_CHECK(cudaSetDevice(d.index()));
    }
    return old_device;
  }
  Device getDevice() const override {
    int device;
    AT_CUDA_CHECK(cudaGetDevice(&device));
    return Device(DeviceType::CUDA, device);
  }
  void setDevice(Device d) const override {
    AT_ASSERT(d.type() == DeviceType::CUDA);
    AT_CUDA_CHECK(cudaSetDevice(d.index()));
  }
  void uncheckedSetDevice(Device d) const noexcept override {
    cudaSetDevice(d.index());
  }
  Stream getStream(Device d) const noexcept override {
    return at::cuda::getCurrentCUDAStream().unwrap();
  }
  // NB: These do NOT set the current device
  Stream exchangeStream(Stream s) const noexcept override {
    CUDAStream cs(s);
    auto old_stream = at::cuda::getCurrentCUDAStream(s.device().index());
    at::cuda::setCurrentCUDAStream(cs);
    return old_stream.unwrap();
  }
};

}}} // namespace at::cuda::impl
