replit.nix

{ pkgs }: {
	deps = [
		pkgs.gnome.gedit
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}		