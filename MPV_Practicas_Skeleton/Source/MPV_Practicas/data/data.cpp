#include "data.h"
#include "HAL/PlatformProcess.h"
#include "Misc/Paths.h"


TArray<TArray<GridLocation>> ParseGridDataFromFile(const FString& FilePath)
{
	TArray<TArray<GridLocation>> ParsedGrid;

	// Read file contents
	FString FileContents;
	FFileHelper::LoadFileToString(FileContents, *FilePath);

	// Split contents into lines
	TArray<FString> Lines;
	FileContents.ParseIntoArrayLines(Lines);

	for (const FString& Line : Lines)
	{
		TArray<FString> Elements;
		Line.ParseIntoArray(Elements, TEXT(";"));

		TArray<GridLocation> Row;
		for (const FString& Element : Elements)
		{
			TArray<FString> Values;
			Element.ParseIntoArray(Values, TEXT(","));

			if (Values.Num() == 4)
			{
				GridLocation Location;
				Location.Location.X = FCString::Atof(*Values[0]);
				Location.Location.Y = FCString::Atof(*Values[1]);
				Location.Location.Z = FCString::Atof(*Values[2]);
				Location.EntryCost = FCString::Atof(*Values[3]);
				Row.Add(Location);
			}
		}
		ParsedGrid.Add(Row);
	}

	return ParsedGrid;
}


