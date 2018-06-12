#ifndef IndiciumDirect3D12_h__
#define IndiciumDirect3D12_h__

#include <dxgi.h>

typedef
_Function_class_(EVT_INDICIUM_D3D12_PRESENT)
VOID
EVT_INDICIUM_D3D12_PRESENT(
    IDXGISwapChain  *pSwapChain,
    UINT            SyncInterval,
    UINT            Flags
);

typedef EVT_INDICIUM_D3D12_PRESENT *PFN_INDICIUM_D3D12_PRESENT;

typedef
_Function_class_(EVT_INDICIUM_D3D12_RESIZE_TARGET)
VOID
EVT_INDICIUM_D3D12_RESIZE_TARGET(
    IDXGISwapChain          *pSwapChain,
    const DXGI_MODE_DESC    *pNewTargetParameters
);

typedef EVT_INDICIUM_D3D12_RESIZE_TARGET *PFN_INDICIUM_D3D12_RESIZE_TARGET;


typedef struct _INDICIUM_D3D12_EVENT_CALLBACKS
{
    ULONG Size;

    PFN_INDICIUM_D3D12_PRESENT          EvtIndiciumD3D12PrePresent;
    PFN_INDICIUM_D3D12_PRESENT          EvtIndiciumD3D12PostPresent;

    PFN_INDICIUM_D3D12_RESIZE_TARGET    EvtIndiciumD3D12PreResizeTarget;
    PFN_INDICIUM_D3D12_RESIZE_TARGET    EvtIndiciumD3D12PostResizeTarget;

} INDICIUM_D3D12_EVENT_CALLBACKS, *PINDICIUM_D3D12_EVENT_CALLBACKS;

VOID
FORCEINLINE
INDICIUM_D3D12_EVENT_CALLBACKS_INIT(
    _Out_ PINDICIUM_D3D12_EVENT_CALLBACKS Callbacks
)
{
    RtlZeroMemory(Callbacks, sizeof(INDICIUM_D3D12_EVENT_CALLBACKS));

    Callbacks->Size = sizeof(INDICIUM_D3D12_EVENT_CALLBACKS);
}

#endif // IndiciumDirect3D12_h__
