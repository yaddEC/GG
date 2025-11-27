#include "GASTest.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"
#include "AbilitySystemComponent.h"
#include "GGHealthSet.h"


IMPLEMENT_SIMPLE_AUTOMATION_TEST(UGasTest, "GAS.Health.ClampAttributeOnChange",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool UGasTest::RunTest(const FString& Parameters)
{
    ADD_LATENT_AUTOMATION_COMMAND(FDelayedFunctionLatentCommand([this]()
    {
        UAbilitySystemComponent* ASC = NewObject<UAbilitySystemComponent>(GetTransientPackage());
        ASC->RegisterComponent();
        
        UGGHealthSet* HealthSet = NewObject<UGGHealthSet>(ASC);
        ASC->AddAttributeSetSubobject(HealthSet);
        
        ASC->SetNumericAttributeBase(UGGHealthSet::GetMaxHealthAttribute(), 100.f);
        ASC->SetNumericAttributeBase(UGGHealthSet::GetMaxShieldAttribute(), 50.f);

        float NewValue = 150.f;
        HealthSet->ClampAttributeOnChange(UGGHealthSet::GetHealthAttribute(), NewValue);
        TestEqual(TEXT("Health clamped to MaxHealth"), NewValue, 100.f);

        NewValue = -10.f;
        HealthSet->ClampAttributeOnChange(UGGHealthSet::GetHealthAttribute(), NewValue);
        TestEqual(TEXT("Health clamped to minimum 0"), NewValue, 0.f);

        NewValue = 75.f;
        HealthSet->ClampAttributeOnChange(UGGHealthSet::GetHealthAttribute(), NewValue);
        TestEqual(TEXT("Health unchanged within bounds"), NewValue, 75.f);

        NewValue = 60.f;
        HealthSet->ClampAttributeOnChange(UGGHealthSet::GetShieldAttribute(), NewValue);
        TestEqual(TEXT("Shield clamped to MaxShield"), NewValue, 50.f);

        NewValue = -5.f;
        HealthSet->ClampAttributeOnChange(UGGHealthSet::GetShieldAttribute(), NewValue);
        TestEqual(TEXT("Shield clamped to minimum 0"), NewValue, 0.f);

        NewValue = 25.f;
        HealthSet->ClampAttributeOnChange(UGGHealthSet::GetShieldAttribute(), NewValue);
        TestEqual(TEXT("Shield unchanged within bounds"), NewValue, 25.f);

        return true;
    }));

    return true; 
}
