//
//  XPCompatibility.h
//  LiveTraffic
//

/*
 * Copyright (c) 2019, Birger Hoppe
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef XPCompatibility_h
#define XPCompatibility_h

// MARK: struct sizes
//       sizes of structs in XPLM210 build
constexpr size_t XPLMCreateWindow_s_210 = offsetof(XPLMCreateWindow_t,decorateAsFloatingWindow);

// MARK: XPC - proxy functions
// this header includes "proxy" function for those functions,
// which are not part of XPLM210 and are therefore called
// via XPLMFindSymbol

void XPC_SetWindowPositioningMode(XPLMWindowID              inWindowID,
                                  XPLMWindowPositioningMode inPositioningMode,
                                  int                       inMonitorIndex);
XPLMWindowID XPC_GetWidgetUnderlyingWindow(XPWidgetID       inWidget);
void XPC_GetAllMonitorBoundsGlobal(XPLMReceiveMonitorBoundsGlobal_f inMonitorBoundsCallback,
                                   void *               inRefcon);

// find and initialize all function pointers
bool XPC_Init();

// X-Plane API
extern int XPC_XPlaneVersion, XPC_XPLMVersion;
inline int XPC_GetXPlaneVer()   { return XPC_XPlaneVersion; }
inline int XPC_GetXPLMVer()     { return XPC_XPLMVersion; }
inline bool XPC_IsXPLM210()     { return XPC_XPLMVersion >= 210; }
inline bool XPC_IsXPLM301()     { return XPC_XPLMVersion >= 301; }
#define IS_XPLM210 (XPC_IsXPLM210())
#define IS_XPLM301 (XPC_IsXPLM301())



// MARK: LT - LiveTraffic global functions
//            working XP-version independent

// determines screen size
// XP10: main screen
// XP11: right-most screen
void LT_GetScreenSize (int& outLeft,
                       int& outTop,
                       int& outRight,
                       int& outBottom); 

#endif /* XPCompatibility_h */
