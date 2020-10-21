package(default_visibility = ["//visibility:public"])


cc_library(
    name = "TripartitionScorer",
    hdrs = ["TripartitionScorer.hpp"],
    srcs = ["TripartitionScorer.cpp"],
    deps = ["//phylonaut/CladeExtractor:CladeExtractor",
            "//phylonaut:Config",
            "@phylokit",
            "@com_github_google_glog//:glog",
            ]
)