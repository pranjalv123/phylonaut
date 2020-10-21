package(default_visibility = ["//visibility:public"])

cc_library(
    name = "CladeExtractor",
    hdrs = ["ASTRALCladeExtractor.hpp",
            "GLOBExtractor.hpp",
            "DefaultTaxonSetExtractor.hpp",
            "SimpleCladeExtractor.hpp"],
    deps = [
        ":ASTRALCladeExtractor", 
        ":GLOBExtractor",
        ":DefaultTaxonSetExtractor",
        ":SimpleCladeExtractor",
        "@phylokit",
        "@com_github_google_glog//:glog",
    ]
)

cc_library(
    name = "whereami",
    hdrs = ["whereami++.hpp", "whereami.h"],
    srcs = ["whereami++.cpp", "whereami.cpp"],
    visibility = ["//visibility:private"]
)

cc_library(
    name = "ASTRALCladeExtractor",
    hdrs = ["ASTRALCladeExtractor.hpp"],
    srcs = ["CladeExtractor.hpp",
            "ASTRALCladeExtractor.cpp",
            "dirent.h"],
    deps = [
        ":whereami", 
        "@phylokit",
        "@com_github_google_glog//:glog",
    ],
)

cc_library(
    name = "SimpleCladeExtractor",
    hdrs = ["SimpleCladeExtractor.hpp"],
    srcs = ["CladeExtractor.hpp",
            "SimpleCladeExtractor.cpp"
    ],
    deps = [
        "@phylokit",
        "@com_github_google_glog//:glog",
        ]
)

cc_library(
    name = "GLOBExtractor",
    hdrs = ["GLOBExtractor.hpp"],
    srcs = ["CladeExtractor.hpp",
            "GLOBExtractor.cpp"],
    deps = [
        "@phylokit",
        "@com_github_google_glog//:glog",
    ]
)

cc_library(
    name = "DefaultTaxonSetExtractor",
    hdrs = ["CladeExtractor.hpp",
            "DefaultTaxonSetExtractor.hpp"],
    srcs = ["DefaultTaxonSetExtractor.cpp"],
    deps = [
        "@phylokit",
        "@com_github_google_glog//:glog",
    ]
)