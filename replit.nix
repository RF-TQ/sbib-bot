{ pkgs }: {
	deps = [
		pkgs.wget
 		pkgs.clang_12
		pkgs.cmake
		pkgs.gdb
		pkgs.openssl
		pkgs.libopus 
		pkgs.zlib 
		pkgs.libsodium
		pkgs.python310
	];
}