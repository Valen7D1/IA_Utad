#ifndef __DATA_H__
#define __DATA_H__

#include <CoreMinimal.h>

struct GridLocation
{
    FVector Location;
    float EntryCost;
};

TArray<TArray<GridLocation>> ParseGridDataFromFile(const FString& FilePath);


#endif