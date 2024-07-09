/* Lucas Robiati Sant'Ana 
*/

#pragma once 
#include<iostream>
#include<filesystem>
#include<memory>
#include<array>
#include<fstream>
#include "cores.hpp"

namespace fs = std::filesystem;

class Limpeza
{
	bool m_debug;
	std::string m_path;

	const std::string m_home = std::getenv("HOME");

	const fs::path m_trash  = ".local/share/Trash/files";
	const fs::path m_thumbs = ".cache/thumbnails";
	const fs::path m_fox    = ".cache/mozilla";
	const fs::path m_recent = ".local/share/recently-used.xbel";
	const fs::path m_zsh_h  = ".zsh_history";

	protected:
		void print(bool, const std::string&);
		bool clean_dir	(const std::array<std::string, 3>& = {});
		bool clean_file (const std::array<std::string, 3>& = {});
	
	public:
		Limpeza(bool);
		void run();
};
