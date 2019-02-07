# mpsoc-library
Library files for Zynq MPSoC (64bit ARM CPU)


## imaging: Library for image I/O and manipulation

- ffmpeg: 4.0.3

- FreeImage: 3.18.0

- OpenCV: 4.0.1


## dl-framework: Deep learning frame works

- caffe: Caffe 1.0

- caffe-dependency: Libraries for building Caffe 1.0

  - boost: 1.68.0
  - gflags: v2.2.2
  - glog: v0.3.5
  - leveldb: v1.20
  - lmdb: v0.9.23
  - HDF5
  - OpenBLAS: v0.3.4
    - Note: v0.3.5 causes compilation error
  - protobuf: v3.6.1
  - snappy: v1.1.7

- protoc-host: protoc executable for x86_64 host

- tlite: TensorFlow Lite (1.12.0)

***

- See [wiki](https://github.com/t-kuha/mpsoc-library/wiki) for how to build these libraryes from source
