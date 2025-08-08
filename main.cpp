#include "ai_bmt_gui_caller.h"
#include "ai_bmt_interface.h"
#include <filesystem>
#include "dxrt/dxrt_api.h"
#include "classification_ONNX.cpp"
#include "classification_DXNN.cpp"

using namespace std;

int main(int argc, char *argv[])
{
    try
    {
        // ONNX
        // shared_ptr<AI_BMT_Interface> interface = make_shared<Classification_Implementation_ONNX>();

        // DXNN
        shared_ptr<AI_BMT_Interface> interface = make_shared<Classification_Implementation_DXNN>();
        AI_BMT_GUI_CALLER caller(interface);
        return caller.call_BMT_GUI(argc, argv);
    }
    catch (const exception &ex)
    {
        cout << ex.what() << endl;
    }
}
