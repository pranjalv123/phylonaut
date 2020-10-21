# phylonaut
Dynamic programming for phylogenetics applications

This is a dependency of FastRFS & SVDquest. 

To build, you will need bazel (https://www.bazel.build/):


    bazel build phylonaut:all

It's easiest to use phylonaut from within a bazel project;
copy the contents of phylonaut's WORKSPACE into your WORKSPACE file.

If you want to use phylonaut from a cmake project, you could try https://github.com/google/bazel-to-cmake.
