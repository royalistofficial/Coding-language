#include "const.hpp"
#include "Grid.hpp"
#include "Ball.hpp"
#include "Plarform.hpp"
#include "bonus.hpp"

class Battlefield {
public:
    Battlefield();
    void newIterationBattlefield();
    Plarform* getPlatform();
    ~Battlefield();
private:
    Grid *grid;
    Plarform *plarform;
    std::vector<Ball*> balls;
    std::vector<Bonus*> bonuses;
};
