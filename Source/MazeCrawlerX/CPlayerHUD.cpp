#include "CPlayerHUD.h"
#include "Components/TextBlock.h"

void UCPlayerHUD::UpdateMaxFoodCount(int32 NewMaxFoodCount)
{
	FText tempText = FText::Format(FText::FromString(TEXT("/ {0}")), NewMaxFoodCount);
	MaxFood->SetText(tempText);
}

void UCPlayerHUD::UpdateFoodCollected(int32 NewFoodCount)
{
	FText tempText = FText::Format(FText::FromString(TEXT("{0} ")), NewFoodCount);
	FoodCollected->SetText(tempText);
}
