package(default_visibility = ["//visibility:public"])

cc_library(
    name = "Analysis",
    hdrs = ["Analysis.hpp", 
            "ConsensusTreeAnalysis.hpp",
            "CountTreesAnalysis.hpp",
            "SingleTreeAnalysis.hpp"
            ],
    deps = [":ConsensusTreeAnalysis", 
            ":CountTreesAnalysis",
            ":SingleTreeAnalysis",
            "@phylokit",
            "@com_github_google_glog//:glog",
    ]
)

cc_library(
    name = "ConsensusTreeAnalysis",
    hdrs = ["ConsensusTreeAnalysis.hpp"],
    srcs = ["Analysis.hpp",
            "ConsensusTreeAnalysis.cpp"],
    deps = [":CountTreesAnalysis",
            "//phylonaut/TripartitionScorer:TripartitionScorer",
            "@phylokit",
            "@com_github_google_glog//:glog",
    ],
)

cc_library(
    name = "CountTreesAnalysis",
    hdrs = ["CountTreesAnalysis.hpp"],
    srcs = ["Analysis.hpp",
            "CountTreesAnalysis.cpp"],
    deps = ["//phylonaut/TripartitionScorer:TripartitionScorer",
            "@phylokit",
            "@com_github_google_glog//:glog",
    ],
)

cc_library(
    name = "SingleTreeAnalysis",
    hdrs = ["SingleTreeAnalysis.hpp"],
    srcs = ["Analysis.hpp",
            "SingleTreeAnalysis.cpp"],
    deps = ["//phylonaut/TripartitionScorer:TripartitionScorer",
            "@phylokit",
            "@com_github_google_glog//:glog",
    ],
)