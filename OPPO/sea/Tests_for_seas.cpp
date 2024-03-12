#include <sstream>
#include "pch.h"
#include "CppUnitTest.h"
#include "fish_additional.h"
#include "sea_additional.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testspr3
{
    TEST_CLASS(Testspr3)
    {
    public:

        TEST_METHOD(invalid_read_fishes)
        {
            struct TestCase 
            {
                std:: string input;
                int count;
            };
            std::vector<TestCase> cases
            {
                TestCase{ "acb 123 a23bc ab401 124", 5 },
                TestCase{ "123 4314 5124 124", 4 },
            };
            for (size_t i = 0; i < cases.size(); i++)
            {
                try
                {
                    std::stringstream sin{ cases[i].input };
                    auto vect = fish::read_fish(sin);
                    Assert::IsFalse(vect.size() == cases[i].count);
                }
                catch (const std::exception&)
                {
                    Assert::Fail();
                }
            }
        }

        TEST_METHOD(valid_values_of_depth_and_salinity)
        {
            struct Values
            {
                double depth;
                double salinity;
            };
            std::vector<Values> cases
            {
                Values{ 59.5, 241.2 },
                Values{ 241.5, 417.9 },
            };
            struct Vector_for_file
            {
                std::string str;
            };
            std::vector<Vector_for_file> ccases
            {
                Vector_for_file{ "\"Abcde\" 59 241 qr qwr rewr" },
                Vector_for_file{ "\"Abcde\" 241 417 qr qwr rewr" },
            };
            for (int i = 0; i < cases.size(); i++)
            {
                try
                {
                    std::stringstream file{ ccases[i].str };
                    const auto vector = sea::read_sea(file);
                    Assert::IsTrue(cases[i].depth != vector[0].depth);
                    Assert::IsTrue(cases[i].salinity != vector[0].salinity);
                }
                catch (const std::exception&)
                {
                    Assert::Fail();
                }
            }
        }

        TEST_METHOD(invalid_values_of_depth_and_salinity)
        {
            struct Values
            {
                double depth;
                double salinity;
            };
            std::vector<Values> cases
            {
                Values{ 59, 241 },
                Values{ 241, 417 },
            };
            struct Vector_for_file
            {
                std::string str;
            };
            std::vector<Vector_for_file> ccases
            {
                Vector_for_file{ "\"Abcde\" 59 241 qr qwr rewr" },
                Vector_for_file{ "\"Abcde\" 241 417 qr qwr rewr" },
            };
            for (int i = 0; i < cases.size(); i++)
            {
                try
                {
                    std::stringstream file{ ccases[i].str };
                    const auto vector = sea::read_sea(file);
                    Assert::IsTrue(cases[i].depth == vector[0].depth);
                    Assert::IsTrue(cases[i].salinity == vector[0].salinity);
                }
                catch (const std::exception&)
                {
                    Assert::Fail();
                }
            }
        }

        TEST_METHOD(valid_read_fishes)
        {
            struct TestCase
            {
                std::string input;
                int count;
            };
            std::vector<TestCase> cases
            {
                TestCase{ "Fish Name Correct Values", 4 },
                TestCase{ "FAsd asdqwr cxzcsdf qwr faasfqwr sacafa", 6},
            };
            for(size_t i = 0; i < cases.size(); i++)
            {
                try 
                {
                    std::stringstream  sin{ cases[i].input };
                    auto vect = fish::read_fish(sin);
                    Assert::IsTrue(vect.size() == cases[i].count);
                }
                catch (const std::exception&)
                {
                    Assert::Fail();
                }
            }
        }
        TEST_METHOD(valid_name_read_names_of_seas)
        {
            std::stringstream sin{ "\"Abc Bcd\"" };
            const auto seas_name = sea::read_name_of_sea(sin);
            Assert::IsTrue(seas_name == "Abc Bcd");
        }

        TEST_METHOD(valid_name_read_fullnames_of_seas)
        {
            std::stringstream sin{ "\"AbcBcd\"" };
            const auto seas_name = sea::read_name_of_sea(sin);
            Assert::IsTrue(seas_name == "AbcBcd");
        }

        TEST_METHOD(valid_init_name_depth_salinity_fishes)
        {
            std::stringstream sin{ "\"Abcde\" 515.0 717.5" };
            const auto vector = sea::read_sea(sin);
            Assert::IsTrue(vector[0].name == "Abcde");
            Assert::IsTrue(vector[0].depth == 515.0);
            Assert::IsTrue(vector[0].salinity == 717.5);
        }

        TEST_METHOD(invalid_name_read_names_of_seas)
        {
            std::stringstream sin{ "\"Abc Bcd\"" };
            const auto seas_name = sea::read_name_of_sea(sin);
            Assert::IsFalse(seas_name != "Abc Bcd");
        }

        TEST_METHOD(invalid_init_depth_is_double)
        {
            std::stringstream sin{ "\"Abcde\" 515.2 717.5" };
            const auto vector = sea::read_sea(sin);
            Assert::IsFalse(vector[0].depth == 515);
        }

        TEST_METHOD(invalid_init_salinity_is_double)
        {

            std::stringstream sin{ "\"Abcde\" 515.0 717.5" };
            const auto vector = sea::read_sea(sin);
            Assert::IsFalse(vector[0].salinity == 717);
        }

        TEST_METHOD(invalid_init_depth)
        {
            std::stringstream sin{ "\"Abcde\" 515.2 717.5" };
            const auto vector = sea::read_sea(sin);
            Assert::IsFalse(vector[0].depth != 515.2);
        }

        TEST_METHOD(invalid_init_salinity)
        {
            std::stringstream sin{ "\"Abcde\" 515.2 717.5" };
            const auto vector = sea::read_sea(sin);
            Assert::IsFalse(vector[0].salinity != 717.5);
        }
    };
}
