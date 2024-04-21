#ifndef __DATA_H__
#define __DATA_H__

#include <CoreMinimal.h>

struct GridLocation
{
    FVector Location;
    float EntryCost;
    int IdX;
    int IdZ;
};

std::vector<std::vector<GridLocation>> ParseGridDataFromFile(const FString& FilePath);


#endif