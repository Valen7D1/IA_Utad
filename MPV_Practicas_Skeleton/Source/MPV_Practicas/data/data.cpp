#include "data.h"
#include "HAL/PlatformProcess.h"
#include "Misc/Paths.h"


std::vector<std::vector<GridLocation>> ParseGridDataFromFile(const FString& FilePath)
{
	std::vector<std::vector<GridLocation>> ParsedGrid;

	// Read file contents
	FString FileContents;
	FFileHelper::LoadFileToString(FileContents, *FilePath);

	// Split contents into lines
	TArray<FString> Lines;
	FileContents.ParseIntoArrayLines(Lines);

	int IdX = 0;
	int IdZ = 0;
	
	for (const FString& Line : Lines)
	{
		TArray<FString> Elements;
		Line.ParseIntoArray(Elements, TEXT(";"));
		
		std::vector<GridLocation> Row;
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
				Location.IdX = IdX;
				Location.IdZ = IdZ;
				Row.push_back(Location);
			}
			++IdZ;
		}
		ParsedGrid.push_back(Row);
		
		++IdX;
		IdZ = 0;
	}

	return ParsedGrid;
}


