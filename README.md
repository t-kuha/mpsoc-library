# mpsoc-library (2018.3)

Library files for Zynq MPSoC (64bit ARM CPU)

## arm: ARM conpute library & NN SDK

- computelibrary: ARM compute library

- nnsdk: ARM NNSDK

- boost & flatbuffers: dependency for ARM NNSDK

## dl-framework: Deep learning frame works

- caffe: Caffe 1.0

- caffe-dependency: Libraries for building Caffe 1.0 & libtorch

  - boost: 1.68.0
  - gflags: v2.2.2
  - glog: v0.3.5
  - leveldb: v1.20
  - lmdb: v0.9.23
  - OpenBLAS: v0.3.4
    - Note: v0.3.5 causes compilation error
  - protobuf: v3.6.1
  - snappy: v1.1.7
  - ZeroMQ: v4.3.2

- chainerx: ChainerX (v6.0.0)

- libtorch: libtorch (part of PyTorch v.1.1.0)

- protoc-host: protoc executable for x86_64 host

- tlite: TensorFlow Lite (1.15.0)

## imaging: Library for image I/O and manipulation

- ffmpeg: 4.0.3

- FreeImage: 3.18.0

- OpenCV: 4.0.1

***

- See [wiki](https://github.com/t-kuha/mpsoc-library/wiki) for how to build these libraries from source
