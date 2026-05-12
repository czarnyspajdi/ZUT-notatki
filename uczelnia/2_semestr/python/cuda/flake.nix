{
  description = "Środowisko dla ZED SDK (ZED 2i) + Python";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs =
    { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs {
        inherit system;
        config = {
          allowUnfree = true;
        };
      };
    in
    {
      devShells.${system}.default =
        let
          fhs = pkgs.buildFHSUserEnv {
            name = "zed-env";
            targetPkgs =
              pkgs: with pkgs; [
                glibc
                gcc-unwrapped.lib
                stdenv.cc.cc.lib
                glib
                zlib
                binutils
                pciutils
                wget
                libusb1

                libGL
                xorg.libX11
                xorg.libXext

                cudaPackages.cudatoolkit
                cudaPackages.cudnn

                (python3.withPackages (
                  ps: with ps; [
                    pip
                    numpy
                    opencv4
                    open3d
                  ]
                ))
              ];

            profile = ''
              export LD_LIBRARY_PATH=/run/opengl-driver/lib:/usr/lib:/usr/lib32:$LD_LIBRARY_PATH
              export CUDA_PATH=${pkgs.cudaPackages.cudatoolkit}

              export PIP_PREFIX=$(pwd)/.local_pip
              export PYTHONPATH=$(pwd)/.local_pip/lib/python3.11/site-packages:$PYTHONPATH
              export PATH=$(pwd)/.local_pip/bin:$PATH
            '';
          };
        in
        fhs.env;
    };
}
