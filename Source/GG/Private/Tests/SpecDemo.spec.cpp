//#include "Misc/AutomationTest.h"
//
//#if WITH_AUTOMATION_TESTS
//BEGIN_DEFINE_SPEC(FExampleSpec, "Project.Demo.Simple",
//    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags:: SmokeFilter);
//
//FString RunOrder;
//
//END_DEFINE_SPEC(FExampleSpec);
//
//void FExampleSpec::Define()
//{
//	Describe("A spec using BeforeEach and AfterEach", [this]()
//	{
//		BeforeEach([this]()
//		{
//			RunOrder = TEXT("A");
//		});
//
//		AfterEach([this]()
//		{
//			RunOrder += TEXT("Z");
//
//			// Can result in
//			// TestEqual("RunOrder", RunOrder, TEXT("ABCYZ"));
//
//			// or this, based on which It() is being executed
//			// TestEqual("RunOrder", RunOrder, TEXT("ABCDXYZ"));
//		});
//
//		BeforeEach([this]()
//		{
//			RunOrder += TEXT("B");
//		});
//
//		Describe("while nested inside another Describe", [this]()
//		{
//			AfterEach([this]()
//			{
//				RunOrder += TEXT("Y");
//			});
//
//			It("will run all BeforeEach blocks and all AfterEach blocks", [this]()
//			{
//				TestEqual("RunOrder", RunOrder, TEXT("ABC"));
//			});
//
//			BeforeEach([this]()
//			{
//				RunOrder += TEXT("C");
//			});
//
//			Describe("while nested inside yet another Describe", [this]()
//			{
//				It("will run all BeforeEach blocks and all AfterEach blocks", [this]()
//				{
//					TestEqual("RunOrder", RunOrder, TEXT("ABCD"));
//				});
//
//				AfterEach([this]()
//				{
//					RunOrder += TEXT("X");
//				});
//
//				BeforeEach([this]()
//				{
//					RunOrder += TEXT("D");
//				});
//			});
//		});
//	});
//}
//#endif
