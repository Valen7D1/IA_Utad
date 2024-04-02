
#include <CoreMinimal.h>

void SetArrow(const AActor* owner, const FString& arrow_name, const FVector& direction, float length);

void SetCircle(const AActor* owner, const FString& circle_name, const FVector& position, float radius);

void SetPath(const AActor* owner, const FString& path_actor_name, const FString& component_name, const TArray<FVector>& PathPoints, float PathThickness, UMaterialInterface* material);