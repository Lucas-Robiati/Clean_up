#include "clean.hpp"

int main(int argc, char** argv){
  bool debug {false};
  std::string param {};
  if(argc > 1){
    param = argv[1];
    if(param == "--debug"){
      debug = true;
    }else{
      std::cerr << "Use: " << argv[0] << " [--debug]\n";
    }
  }
  auto lp = std::make_unique<Limpeza>(debug);
  lp->run();
  return 0;
}
