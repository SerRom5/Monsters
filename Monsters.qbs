import qbs

CppApplication {
    consoleApplication: true
    files: [
        "creature.cpp",
        "creature.h",
        "gameprocess.cpp",
        "gameprocess.h",
        "main.cpp",
        "monster.cpp",
        "monster.h",
        "player.cpp",
        "player.h",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
