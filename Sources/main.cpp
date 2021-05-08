#include <iostream>

#include "CAssets.h"
#include "CGameModel.h"
#include "CGameView.h"
#include "CGameController.h"
#include "../Timer/CTimer.h"

int main() {
    CAssets::GetInstance().Load();
    CGameModel Model;

    CGameView View(&Model);

    CGameController Controller(&Model, &View);

    CTimer timer;
    Controller.Run();

    std::cout << timer.elapsed();
    return 0;
}


