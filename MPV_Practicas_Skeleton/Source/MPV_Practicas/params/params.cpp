#include "params.h"

#include "XmlFile.h"
#include "Misc/DefaultValueHelper.h"
#include "HAL/PlatformProcess.h"
#include "Misc/Paths.h"


bool ReadParams(const char* filename, Params& params)
{
	FString CurrentDirectory = FPlatformProcess::GetCurrentWorkingDirectory();

	// Log or use the current working directory
	UE_LOG(LogTemp, Log, TEXT("Current working directory: %s"), *CurrentDirectory);

	FString ContentFolderDir = FPaths::ProjectContentDir();

	//FString FilePath(TEXT("./params.xml"));
	FString params_path = filename;
	FString FilePath = FPaths::Combine(*ContentFolderDir, *params_path);
	UE_LOG(LogTemp, Log, TEXT("Params Path: %s"), *FilePath);

	
	FXmlFile MyXml(FilePath, EConstructMethod::ConstructFromFile);
	
	if (MyXml.GetRootNode())
	{
		const FXmlNode* RootNode = MyXml.GetRootNode();
	
		const FString MyChildTag("params");
		const FXmlNode* MyChildNode = RootNode->FindChildNode(MyChildTag);

		// max_velocity
		const FXmlNode* paramElem = MyChildNode->FindChildNode(TEXT("max_velocity"));
		FString value;
		if (paramElem)
		{
			value = paramElem->GetAttribute("value");
			FDefaultValueHelper::ParseFloat(value, params.max_velocity);
		}

		// max_acceleration
		paramElem = MyChildNode->FindChildNode(TEXT("max_acceleration"));
		if (paramElem)
		{
			value = paramElem->GetAttribute("value");
			FDefaultValueHelper::ParseFloat(value, params.max_acceleration);
		}

		// dest_radius
		paramElem = MyChildNode->FindChildNode(TEXT("dest_radius"));
		if (paramElem)
		{
			value = paramElem->GetAttribute("value");
			FDefaultValueHelper::ParseFloat(value, params.dest_radius);
		}

		// max_angular_velocity
		paramElem = MyChildNode->FindChildNode(TEXT("max_angular_velocity"));
		if (paramElem)
		{
			value = paramElem->GetAttribute("value");
			FDefaultValueHelper::ParseFloat(value, params.max_angular_velocity);
		}

		// max_angular_acceleration
		paramElem = MyChildNode->FindChildNode(TEXT("max_angular_acceleration"));
		if (paramElem)
		{
			value = paramElem->GetAttribute("value");
			FDefaultValueHelper::ParseFloat(value, params.max_angular_acceleration);
		}

		// angular_arrive_radius
		paramElem = MyChildNode->FindChildNode(TEXT("angular_arrive_radius"));
		if (paramElem)
		{
			value = paramElem->GetAttribute("value");
			FDefaultValueHelper::ParseFloat(value, params.angular_arrive_radius);
		}

		// targetRotation
		paramElem = MyChildNode->FindChildNode(TEXT("targetRotation"));
		if (paramElem)
		{
			value = paramElem->GetAttribute("value");
			FDefaultValueHelper::ParseFloat(value, params.targetRotation);
		}

		// look_ahead
		paramElem = MyChildNode->FindChildNode(TEXT("look_ahead"));
		if (paramElem)
		{
			value = paramElem->GetAttribute("value");
			FDefaultValueHelper::ParseFloat(value, params.look_ahead);
		}



		// targetPosition
		paramElem = MyChildNode->FindChildNode(TEXT("targetPosition"));
		if (paramElem)
		{
			value = paramElem->GetAttribute("x");
			float x;
			FDefaultValueHelper::ParseFloat(value, x);
			params.targetPosition.X = x;
			value = paramElem->GetAttribute("z");
			float z;
			FDefaultValueHelper::ParseFloat(value, z);
			params.targetPosition.Z = z;
			params.targetPosition.Y = 0.0f;
		}
	}
	return true;
}

bool ReadPath(const char* filename, Params& params)
{
	FString CurrentDirectory = FPlatformProcess::GetCurrentWorkingDirectory();

	// Log or use the current working directory
	UE_LOG(LogTemp, Log, TEXT("Current working directory: %s"), *CurrentDirectory);

	FString ContentFolderDir = FPaths::ProjectContentDir();

	//FString FilePath(TEXT("./params.xml"));
	FString params_path = filename;
	FString FilePath = FPaths::Combine(*ContentFolderDir, *params_path);
	UE_LOG(LogTemp, Log, TEXT("Path Path: %s"), *FilePath);

	
	FXmlFile MyXml(FilePath, EConstructMethod::ConstructFromFile);
	
	if (MyXml.GetRootNode())
	{
		const FXmlNode* RootNode = MyXml.GetRootNode();
	
		const FString MyChildTag("points");
		const FXmlNode* MyPoints = RootNode->FindChildNode(MyChildTag);
			
		TArray<FXmlNode*> Points = MyPoints->GetChildrenNodes();

		FVector temp = FVector::Zero();
		FString value;
		for (FXmlNode* Node: Points)
		{
			value = Node->GetAttribute("x");
			float x;
			FDefaultValueHelper::ParseFloat(value, x);
			temp.X = x;
			value = Node->GetAttribute("y");
			float y;
			FDefaultValueHelper::ParseFloat(value, y);
			temp.Z = y;

			params.path.Add(temp);
		}
	}
	
	return true;
}

bool ReadObstacles(const char* filename, Params& params)
{
	FString CurrentDirectory = FPlatformProcess::GetCurrentWorkingDirectory();

	// Log or use the current working directory
	UE_LOG(LogTemp, Log, TEXT("Current working directory: %s"), *CurrentDirectory);

	FString ContentFolderDir = FPaths::ProjectContentDir();

	//FString FilePath(TEXT("./params.xml"));
	FString params_path = filename;
	FString FilePath = FPaths::Combine(*ContentFolderDir, *params_path);
	UE_LOG(LogTemp, Log, TEXT("Obstacles Path: %s"), *FilePath);

	
	FXmlFile MyXml(FilePath, EConstructMethod::ConstructFromFile);
	
	if (MyXml.GetRootNode())
	{
		const FXmlNode* RootNode = MyXml.GetRootNode();
	
		const FString MyChildTag("obstacles");
		const FXmlNode* MyPoints = RootNode->FindChildNode(MyChildTag);
			
		TArray<FXmlNode*> Points = MyPoints->GetChildrenNodes();

		FVector temp = FVector::Zero();
		FString value;
		for (FXmlNode* Node: Points)
		{
			value = Node->GetAttribute("x");
			float x;
			FDefaultValueHelper::ParseFloat(value, x);
			temp.X = x;
			
			value = Node->GetAttribute("y");
			float y;
			FDefaultValueHelper::ParseFloat(value, y);
			temp.Z = y;
			
			value = Node->GetAttribute("r");
			float r;
			FDefaultValueHelper::ParseFloat(value, r);
			temp.Y = r;

			params.obstacles.Add(temp);
		}
	}
	
	return true;
}