#include "Core/core.h"

int main(int argc, char *argv[]){
  Core core;

  core.Init();
  core.Run();
  core.Destroy();

  return 0;
}
