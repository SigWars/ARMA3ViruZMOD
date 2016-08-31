#define ItemMacro(nameN,dispName,classN,EdClassN) \
    class Item_##nameN## : Item_Base_F {\
            scope = 2;\
            scopeCurator = 2;\
            displayName = ##dispName##;\
            author=$STR_RHSUSF_AUTHOR_FULL;\
            vehicleClass = ##classN##;\
            editorSubcategory = ##EdClassN##;\
            model = \A3\Weapons_f\dummyweapon.p3d;\
            class TransportItems {\
                class ##nameN## {\
                name = ##nameN##;\
                count = 1;\
            };\
        };\
    };

class Item_Base_F;

ItemMacro(rds_car_FirstAidKit,"Car First Aid Kit","Items","EdSubcat_InventoryItems")
ItemMacro(rds_car_warning_triangle_to11,"Warning Triangle TO-11","Items","EdSubcat_InventoryItems")