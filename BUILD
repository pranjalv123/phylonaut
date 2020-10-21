config_setting(
    name = "is_windows",
    constraint_values = [
        "@platforms//os:windows",
    ],
)

config_setting(
    name = "is_linux",
    constraint_values = [
        "@platforms//os:linux",
    ],
)

config_setting(
    name = "is_mac",
    constraint_values = [
        "@platforms//os:osx",
    ],
)

cc_library(
    name = "phylonaut",
    deps = [
        "//phylonaut/Analysis:Analysis",
        "//phylonaut/CladeExtractor:CladeExtractor",
        "//phylonaut/TripartitionScorer:TripartitionScorer",
        "//phylonaut:wASTRAL",
        "//phylonaut:Config"
    ],
    hdrs = glob([
        "//phylonaut/**:*.hpp",
    ])
    visibility = ["//visibility:public"],
)