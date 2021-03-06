The Intel CS for WebRTC Client Windows SDK Documentation
===============================
# 1 Introduction {#section1}
The Intel CS for WebRTC Client SDK for Windows provides the tools for developing Windows native WebRTC
applications using C++ APIs. This document describes all the APIs available in the SDK and how to use them.
This SDK is interoperable with the Intel CS WebRTC Client SDK for JavaScript\*, iOS\* and Android\*.
Refer to the Release Notes for the latest information in the SDK release package, including features,
bug fixes and known issues.
# 2 Supported platforms {#section2}
The Intel CS for WebRTC Client SDK for Windows supports Windows 7 and later versions.
# 3 Getting started {#section3}
Application on Intel CS for WebRTC Client SDK for Windows should be built with Microsoft Visual Studio\* 2015 or 2017. Running time library for linking should be `Multi-threaded Debug (/MTd)` for debug version or `Multi-threaded (/MT)` for release version. Supported platforms are x86 and x64.
The release package includes one sample application to get you started quickly with the SDK. The following two static libraries are provided in the SDK for both x86 and x64, along with their headers:
- oms-debug.lib - this library includes all the WebRTC features for debug usages.
- oms-release.lib - this library includes all the WebRTC features for release usages.
oms-debug.lib|oms-release references libraries in Windows SDK for DXVA support. Your application must statically link
mfuuid.lib, mf.lib, mfplat.lib, d3d9.lib, dxgi.lib, d3d11.lib and dxva2.lib to build. Depending on your signaling
channel implementation, you can optionally link sioclient.lib or sioclient_tls.lib if neccessary.
# 4 Socket.IO {#section4}
Socket.IO cpp client is an open source project hosted on [Github](https://github.com/socketio/socket.io-client-cpp).
The Socket.IO TLS feature is determined at compile time and cannot be switched at runtime. If you are using secure
connections, link your application statically with sioclient_tls.lib; otherwise, link it with sioclient.lib. Please be noted the SDK library is linking to SSL1.1.0h, so sioclient_tls.lib must be compiled using the same SSL version.
# 5 NAT and firewall traversal {#section5}
Intel CS for WebRTC Client SDK for Windows fully supports NAT and firewall traversal with STUN / TURN / ICE. The Coturn TURN server from https://github.com/coturn/coturn can be one choice.
# 6 Customize signaling channel {#section6}
Signaling channel is an implementation to transmit signaling data for creating a WebRTC session. Signaling channel
for P2P sessions can be customized by implementing `P2PSignalingChannelInterface`. A default
`P2PSocketSignalingChannel` implementation is provided in the sample, which works with PeerServer.
`PeerClient` implements `P2PSignalingChannelInterfaceObserver` and will be registered into signaling channel, so you
can invoke its methods to notify `PeerClient` during your customized signaling channel implementation when a new
message is coming or connection is lost.
# 7 Video codecs {#section7}
For the decoder, if hardware acceleration is not enabled, only VP8/VP9/H264 is supported. If hardware acceleration is enabled, VP8,
VP9, H.264 and HEVC are supported, but it will fallback to VP8 software decoder if GPU does not supports VP8 hardware decoding.
Most of the 5th/6th/7th/8th Generation Intel<sup>®</sup> Core(TM) Processor platforms support VP8 hardware decoding, refer to their specific documentation for details.
Starting from 6th Generation Intel<sup>®</sup> Core(TM) Processor platforms, hardware encoding and decoding of HEVC is supported. 
Hardware acceleration for decoding of VP8/H.264/HEVC, and encoding of H.264/HEVC, is enabled via {@link oms.base.GlobalConfiguration GlobalConfiguration} API,
by providing valid rendering target to the SetCodecHardwareAccelerationEnabled API before creating conferenceclient or peerclient.
# 8 Publish streams with customized frames {#section8}
Customized video frames can be I420 frame from yuv file, or encoded H.264/VP8/VP9/HEVC frames.
For raw YUV frame input, the customized video frame provider needs to implement its own frame generator extending from
{@link oms.base.VideoFrameGeneratorInterface VideoFrameGeneratorInterface}, which generates customized frames as our sample code and feeds the frame generator to
{@link oms.base.LocalCustomizedStream LocalCustomizedStream} for stream publishing.
For encoded frame input, application is required to implement the customized encoder that inherits
{@link oms.base.VideoEncoderInterface VideoEncoderInterface}, and is required to pass an AU to SDK according to the frame type requested per
{@link oms.base.VideoEncoderInterface.EncodeOneFrame EncodeOneFrame} call.
Customized audio frames provider should implement {@link oms.base.AudioFrameGeneratorInterface AudioFrameGeneratorInterface}. Currently, 16-bit little-endian PCM is supported. Please use {@link oms.base.GlobalConfiguration.SetCustomizedAudioInputEnabled GlobalConfiguration.SetCustomizedAudioInputEnabled} to enable customized audio input.
# 9 Known issues {#section9}
Here is a list of known issues:
- Conference recording from Windows SDK is not supported.
- If you create multiple `LocalCameraStream`s with different resolutions, previous streams will be black.

> Note: \* Other names and brands may be claimed as the property of others.</i>
