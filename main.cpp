#include "ai_bmt_gui_caller.h"
#include "ai_bmt_interface.h"
#include <filesystem>
#include "dxrt/dxrt_api.h"
#include "classification_ONNX.cpp"
#include "classification_DXNN.cpp"

using namespace std;

int main(int argc, char *argv[])
{
    filesystem::path exePath = filesystem::absolute(argv[0]).parent_path(); // Get the current executable file path
    try
    {
        // ONNX
        // filesystem::path model_path = exePath / "Model" / "onnx" / "mobilenet_v2_opset10.onnx";
        // shared_ptr<AI_BMT_Interface> interface = make_shared<Classification_Implementation_ONNX>();

        // DXNN
        filesystem::path model_path = exePath / "Model" / "dxnn" / "mobilenet_v2_opset10.dxnn";
        shared_ptr<AI_BMT_Interface> interface = make_shared<Classification_Implementation_DXNN>();

        string modelPath = model_path.string();
        AI_BMT_GUI_CALLER caller(interface, modelPath);
        return caller.call_BMT_GUI(argc, argv);
    }
    catch (const exception &ex)
    {
        cout << ex.what() << endl;
    }
}