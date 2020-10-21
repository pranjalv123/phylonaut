package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "libphylonaut.so",
    srcs = [
        ":wASTRAL",
        "//phylonaut/TripartitionScorer:TripartitionScorer",
        "//phylonaut/Analysis:SingleTreeAnalysis",
        "//phylonaut/Analysis:CountTreesAnalysis",
        "//phylonaut/Analysis:ConsensusTreeAnalysis",        
        "//phylonaut/CladeExtractor:SimpleCladeExtractor",
        "//phylonaut/CladeExtractor:GLOBExtractor",
        "//phylonaut/CladeExtractor:ASTRALCladeExtractor",
        "//phylonaut/CladeExtractor:DefaultTaxonSetExtractor",
    ],
    linkshared = 1,
    linkstatic = 1,
)

cc_library(
    name = "Config",
    hdrs = ["Config.hpp"],
    deps = ["@phylokit"],
)

cc_library(
    name = "wASTRAL",
    hdrs = ["wASTRAL.hpp"],
    srcs = ["wASTRAL.cpp"],
    deps = [
        "//phylonaut/CladeExtractor:CladeExtractor",
        "//phylonaut/TripartitionScorer:TripartitionScorer",
        "//phylonaut/Analysis:Analysis",
        ":Config",
        "@phylokit"
    ]
)