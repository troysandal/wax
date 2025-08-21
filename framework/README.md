To build wax framework, please follow these steps below.  Because the framework is static, apps using it must link with `-ObjC` to force inclusion of category object files.  In the app project go to Build Settings → Other Linker Flags and add `-ObjC`.  If adding this flag globally causes issues you can instead use `-force_load $(PROJECT_DIR)/framework/wax.xcframework` (latter not verified).

* `cd WAX_ROOT/tools/Framework`
* `rake package`
* then wax.framework will be here
