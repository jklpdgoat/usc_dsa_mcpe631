with import <nixpkgs> {};
clangStdenv.mkDerivation {
  name = "dev-shell";

  src = ./.;
  
  nativeBuildInputs = [
    # pkg-config
    cmake
    bear
    # clang 

    clang-tools
 
    llvmPackages_latest.lldb
    llvmPackages_latest.libllvm
    llvmPackages_latest.libstdcxxClang

    cmake-language-server
  ];
  buildInputs = [
    # sfml
    SDL2
    SDL2.dev
    # gtk3
    # qt5.full
    pkgconfig
    cmake-language-server
    # clang
    ncurses
    llvmPackages_latest.libstdcxxClang

    meson
    ninja
    # zeromq
    # zlib
    # cryptsetup
    # libglvnd
  ];
}