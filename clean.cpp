#include "clean.hpp"

Limpeza::Limpeza(bool debug) : m_debug(debug){
	m_path = {};
}

void Limpeza::run()
{
  this->clean_dir({m_trash, "Lixeira esvaziada", "esvaziar lixeira"});
  if(m_debug){ std::cout << hey::yellow << m_path << hey::off << "\n\n";}

  this->clean_file({m_recent, "Arquivos recentes limpados", "limpar arquivos recentes"});
  if(m_debug){ std::cout << hey::yellow << m_path << hey::off << "\n\n";}

  this->clean_file({m_zsh_h, "Histórico do zsh removido", "limpar histórico do zsh"});
  if(m_debug){ std::cout << hey::yellow << m_path << hey::off << "\n\n";}

  this->clean_dir({m_thumbs, "Thumbnails removidas", "remover cache das Thumbnails"});
  if(m_debug){ std::cout << hey::yellow << m_path << hey::off << "\n\n";}

  this->clean_dir({m_fox, "Cache do Firefox limpado", "remover cache do Firefox"});
  if(m_debug){ std::cout << hey::yellow << m_path << hey::off << "\n\n";}
}

void Limpeza::print(bool action, const std::string& msg)
{
	 (action) ? std::cout << hey::green + "\u2705 " + msg + " com sucesso!" + hey::off << '\n' :
    					std::cerr << hey::red + "\u274C Falha ao " + msg + "." + hey::off << '\n';
}

bool Limpeza::clean_dir(const std::array<std::string, 3>& arr)
{
  m_path = m_home + '/' + arr[0];
  if(m_debug)
	{
    this->print(true, arr[1]);
    return true;
  }

  try
	{
    if (fs::exists(m_path) && fs::is_directory(m_path)) 
		{
      if (fs::is_empty(m_path)) 
			{
        return false;
      }
			else
			{
        if(fs::remove_all(m_path))
				{
          this->print(true, arr[1]);
          fs::create_directory(m_path);
        }
				else
				{
          this->print(false, arr[2]);
          return false;
        }
      }
    }
		else
		{
      return false;
    }
  }
	catch (const fs::filesystem_error& e)
	{
    std::cerr << "EXECUTAR ESSA AÇÃO: " << e.what() << '\n';
    return false;
  }
  return true;
}

bool Limpeza::clean_file(const std::array<std::string, 3>& arr){
  m_path = m_home + '/' + arr[0];
  if(m_debug)
	{
    this->print(true, arr[1]);
    return true;
  }

  try 
	{
    if (fs::exists(m_path) && fs::is_regular_file(m_path)) 
		{
      std::size_t size = std::filesystem::file_size(m_path);
      if(size == 0)
			{
        return false;
      }
      if(fs::remove_all(m_path))
			{
        this->print(true, arr[1]);
        std::ofstream out(m_path);
        out.close();
      }
			else
			{
        this->print(false, arr[2]);
        return false;
      }
    }
		else
		{
      return false;
    }
  }
	catch (const fs::filesystem_error& e)
	{
    std::cerr << "EXECUTAR ESSA AÇÃO: " << e.what() << '\n';
    return false;
  }
  return true;
}
