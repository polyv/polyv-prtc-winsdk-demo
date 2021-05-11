#ifndef _IPRTC_ENGINE_SDK_H_
#define _IPRTC_ENGINE_SDK_H_

#include "PRTCComDefine.h"

class _EXPORT_API PRTCEventListener 
{
 public:
     virtual void onServerDisconnect() {}
     ///加入房间回调
     ///@param code 错误码  0成功
     ///@param msg 错误信息
     ///@param uid 用户id
     ///@param roomid 房间id
     virtual void onJoinRoom(int code,
                             const char* msg,
                             const char* uid,
                             const char* roomid) {}

     ///离开房间回调
     ///@param code 错误码  0成功
     ///@param msg 错误信息
     ///@param uid 用户id
     ///@param roomid 房间id
     virtual void onLeaveRoom(int code,
                              const char* msg,
                              const char* uid,
                              const char* roomid) {}

     ///断线重连回调
     ///@param uid 用户id
     ///@param roomid 房间id
     virtual void onRejoining(const char* uid, const char* roomid) {}

     ///重新加入房间成功回调
     ///@param uid 用户id
     ///@param roomid 房间id
     virtual void onReJoinRoom(const char* uid, const char* roomid) {}

     ///本地流发布回调
     ///@param code 错误码  0 succ
     ///@param msg 本地发布错误信息
     ///@param info 发布成功后本地流信息
     virtual void onLocalPublish(const int code,
                                 const char* msg,
                                 tPRTCStreamInfo& info) {}

     ///本地流取消发布回调
     ///@param code 错误码  0 succ
     ///@param msg 本地发布错误信息
     ///@param info 取消发布成功后本地流信息
     virtual void onLocalUnPublish(const int code,
                                   const char* msg,
                                   tPRTCStreamInfo& info) {}

     ///远端用户加入回调
     ///@param uid 远端用户id
     virtual void onRemoteUserJoin(const char* uid) {}

     ///远端用户离开回调
     ///@param uid 远端用户id
     ///@param reson 离开原因
     virtual void onRemoteUserLeave(const char* uid, int reson) {}

     ///远端流发布回调
     ///@param info 远端流信息
     virtual void onRemotePublish(tPRTCStreamInfo& info) {}

     ///远端流取消发布回调
     ///@param info 远端流信息
     virtual void onRemoteUnPublish(tPRTCStreamInfo& info) {}

     ///订阅回调
     ///@param code 订阅结果 0 succ
     ///@param msg 订阅提示信息
     ///@param info 订阅流信息
     virtual void onSubscribeResult(const int code,
                                    const char* msg,
                                    tPRTCStreamInfo& info) {}

     ///取消订阅回调
     ///@param code 取消订阅结果 0 succ
     ///@param msg 订阅提示信息
     ///@param info 订阅流信息
     virtual void onUnSubscribeResult(const int code,
                                      const char* msg,
                                      tPRTCStreamInfo& info) {}

     ///本地mute回调
     ///@param code mute回调结果 0 succ
     ///@param msg  提示信息
     ///@param mediatype 媒体类型
     ///@param tracktype track类型
     ///@param mute mute状态
     virtual void onLocalStreamMuteRsp(const int code,
                                       const char* msg,
                                       ePRTCMeidaType mediatype,
                                       ePRTCTrackType tracktype,
                                       bool mute) {}

     ///远端mute回调
     ///@param code mute回调结果 0 succ
     ///@param msg  提示信息
     ///@param uid  远端用户id
     ///@param mediatype 媒体类型
     ///@param tracktype track类型
     ///@param mute mute状态
     virtual void onRemoteStreamMuteRsp(const int code,
                                        const char* msg,
                                        const char* uid,
                                        ePRTCMeidaType mediatype,
                                        ePRTCTrackType tracktype,
                                        bool mute) {}

     ///远端音频轨或者视频轨状态回调
     ///@param uid  远端用户id
     ///@param mediatype 媒体类型
     ///@param tracktype track类型
     ///@param mute mute状态
     virtual void onRemoteTrackNotify(const char* uid,
                                      ePRTCMeidaType mediatype,
                                      ePRTCTrackType tracktype,
                                      bool mute) {}

     ///开启录制回调
     ///@param code  0 succ
     ///@param msg 错误提示信息
     ///@param info 录制信息
     virtual void onStartRecord(const int code,
                                const char* msg,
                                tPRTCRecordInfo& info) {}

     ///停止录制回调
     ///@param code  0 succ
     ///@param msg 错误提示信息
     ///@param recordid 录制ID
     virtual void onStopRecord(const int code,
                               const char* msg,
                               const char* recordid) {}

     ///本地数据统计回调
     ///@param rtstats 统计信息
     virtual void onSendRTCStats(tPRTCStreamStats& rtstats) {}

     ///远端数据统计回调
     ///@param rtstats 统计信息
     virtual void onRemoteRTCStats(tPRTCStreamStats rtstats) {}

     ///远端音频能量回调
     ///@param uid 用户ID
     ///@param volume 音量大小
     virtual void onRemoteAudioLevel(const char* uid, int volume) {}

     ///网络评分回调
     ///@param uid 用户ID
     ///@param rtype 网络上下型类型
     ///@param Quality 评分
     virtual void onNetworkQuality(const char* uid,
                                   ePRTCNetworkQuality& rtype,
                                   ePRTCQualityType& Quality) {}

     ///旁推状态回调
     ///@param state rtmp状态
     ///@param url cdn地址
     ///@param code 错误码
     virtual void onRtmpStreamingStateChanged(const int state,
                                              const char* url,
                                              int code){};

     ///旁推更新混合流回调
     ///@param cmd 操作类型
     ///@param code 错误码
     ///@param msg 错误信息
     virtual void onRtmpUpdateMixStreamRes(ePRTCRtmpOpration& cmd,
                                           const int code,
                                           const char* msg){};

     ///设备报错回调
     ///@param code 设备报错回调
     virtual void onCaptureError(const int code, const int detail) {}

     ///本地音频能量回调
     ///@param volume 音量大小
     virtual void onLocalAudioLevel(int volume) {}

     ///远端音频播放首帧回调
     ///@param uid 用户id
     ///@param elapsed 从加入房间到收到远端音频距离的时间
     virtual void onFirstRemoteAudioFrame(const char* uid, int elapsed) {}

     ///远端视频首帧回调
     ///@param uid 用户id
     ///@param width 宽度
     ///@param height 高度
     ///@param elapsed 从加入房间到收到远端视频渲染距离的时间
     virtual void onFirstRemoteVideoFrame(const char* uid,
                                          int width,
                                          int height,
                                          int elapsed) {}

     ///踢人通知
     ///@param code 错误码
     virtual void onKickoff(int code) {}

     ///警告回调
     ///@param warn 错误码
     virtual void onWarning(int warn) {}

     ///错误回调
     ///@param error 错误码
     virtual void onError(int error) {}
};

class _EXPORT_API IPRTCEngine {
 public:
    ///创建引擎
    ///@param bIsInline 是否采用自采集
    ///@return 创建出的engine
    static IPRTCEngine* sharedInstance(bool bIsInline = true);
    static IPRTCEngine* sharedInstance(tPRTCInitContext* context);
    
    ///销毁引擎
    static void destroy();
    
    ///获取sdk版本
    ///@return sdk版本号
    static const char* getSdkVersion();
    
    ///注册监听
    ///@param listener 派生自回调接口的实例
    virtual void regRtcEventListener(PRTCEventListener* listener) = 0;
    
    ///设置sdk模式
    ///@param mode sdk使用模式 正式模式 测试模式
    ///@return 0 succ
    virtual int setSdkMode(ePRTCSdkMode mode) = 0;
    
    ///设置接入方式
    ///@param from 接入点设置
    ///@return 0 succ
    virtual int setServerGetFrom(ePRTCServerGetFrom from) = 0;
    
    ///设置频道类别
    ///@param roomtype 房间类型 大班 小班
    ///@return 0 succ
    virtual int setChannelType(ePRTCChannelType roomtype) = 0;
    
    ///设置角色
    ///@param role 推流 拉流 推拉流
    ///@return 0 succ
    virtual int setStreamRole(ePRTCUserStreamRole role) = 0;
    
    ///设置日志级别
    ///@param level 日志级别
    virtual void setLogLevel(ePRTCLogLevel level) = 0;
    
    ///设置key
    ///@param seckey 官网控制台的appkey
    virtual void setTokenSecKey(const char* seckey) = 0;
    
    ///设置自动发布
    ///@param autoPub 自动发布
    ///@param autoSub 自动订阅
    ///@return 0 succ
    virtual int setAutoPublishSubscribe(bool autoPub, bool autoSub) = 0;
    
    ///设置是否纯音频
    ///@param audioOnly 是否纯音频
    ///@return 0 succ
    virtual int setAudioOnlyMode(bool audioOnly) = 0;
    
    ///设置编码
    ///@param codec 编码类型
    ///@return 0 succ
    virtual int setVideoCodec(ePRTCVideoCodec codec) = 0;
    
    ///该方法用于注册语音观测器对象
    ///@param codec 编码类型
    virtual void registerAudioFrameObserver(
        PRTCIAudioFrameObserver* observer) = 0;
    
    ///该方法用于注册视频观测器对象
    ///@param codec 编码类型
    virtual void registerVideoFrameObserver(
        PRTCIVideoFrameObserver* observer) = 0;
    
    ///开启rtsp推流
    ///@param type 媒体类型
    ///@param enable 是否使用扩展rtsp流
    ///@param rtspurl rtsp地址
    ///@return 0 succ
    virtual int enableExtendRtspVideocapture(ePRTCMeidaType type,
                                             bool enable,
                                             const char* rtspurl) = 0;
    
    ///开启外部采集视频
    ///@param enable 是否使用扩展的外部采集摄像头
    ///@param videocapture 外部视频源
    ///@return 0 succ
    virtual int enableExtendVideocapture(
        bool enable,
        PRTCExtendVideoCaptureSource* videocapture) = 0;
    
    ///初始化外部音频源
    ///@param audiocapture 外部音频源
    ///@return 0 succ
    virtual int initExtendAudioSource(
        PRTCExtendAudioCaptureSource* audiocapture) = 0;
    
    ///开启外部采集音频
    ///@param enable 是否使用扩展的外部采集音频
    ///@param audiocapture 外部音频源(note :必须先初始化initExtendAudioSource一次)
    ///@return 0 succ
    virtual int enableExtendAudiocapture(
        bool enable,
        PRTCExtendAudioCaptureSource* audiocapture) = 0;
    
    ///开启混音
    ///@param filepath 文件路径
    ///@param replace 是否替代麦克风
    ///@param loop 是否循环
    ///@param musicvol 音量
    ///@return 0 succ
    virtual int startAudioMixing(const char* filepath,
                                 bool replace,
                                 bool loop,
                                 float musicvol) = 0;
    
    ///停止混音
    ///@return 0 succ
    virtual int stopAudioMixing() = 0;
    
    ///注册音频接收回调
    ///@param callback 派生自AudioFrameCallback 的实例 (note
    ///:在setChanleType后调用)
    ///@return 0 succ
    virtual void regAudioFrameCallback(PRTCAudioFrameCallback* callback) = 0;
    
    ///注册设备插拔通知回调
    ///@param callback 派生自PRTCDeviceChanged 的实例
    ///@return 0 succ
    virtual void regDeviceChangeCallback(PRTCDeviceChanged* callback) = 0;
    
    ///加入房间
    ///@param auth 鉴权信息
    ///@return 0 succ
    virtual int joinChannel(tPRTCAuth& auth) = 0;
    
    ///离开房间
    ///@return 0 succ
    virtual int leaveChannel() = 0;
    
    ///获取桌面数目
    ///@return 数目
    virtual int getDesktopNums() = 0;
    
    ///获取桌面信息
    ///@param pos 位置
    ///@param [out] info 桌面信息
    ///@return 0 succ
    virtual int getDesktopInfo(int pos, tPRTCDeskTopInfo& info) = 0;
    
    ///获取窗口数目
    virtual int getWindowNums() = 0;
    
    ///获取桌面窗口信息
    ///@param pos 位置
    ///@param [out] info 窗口信息
    ///@return 0 succ
    virtual int getWindowInfo(int pos, tPRTCDeskTopInfo& info) = 0;
    
    ///设置桌面分享类型
    ///@param desktoptype 卓面类型
    ///@return 0 succ
    virtual int setUseDesktopCapture(ePRTCDesktopType desktoptype) = 0;
    
    ///设置桌面分享profile
    ///@param profile 分辨率
    virtual void setDesktopProfile(ePRTCScreenProfile profile) = 0;
    
    ///设置桌面分享参数
    ///@param pgram 分享参数
    virtual void setCaptureScreenPagrams(tPRTCScreenPargram& pgram) = 0;
    
    ///设置加入房间前是否开启摄像头
    ///@param mute 是否禁掉视频  true：禁止 false:否
    ///@return 0 succ
    virtual int muteCamBeforeJoin(bool mute) = 0;
    
    ///设置加入房间前是否mute mic
    ///@param mute 是否禁掉mic  true：禁止 false:否
    ///@return 0 succ
    virtual int muteMicBeforeJoin(bool mute) = 0;
    
    ///设置订阅成功后是否mute摄像头
    ///@param mute 是否禁掉视频  true：禁止 false:否
    ///@return 0 succ
    virtual int muteRomoteCamBeforeSub(bool mute) = 0;
    
    ///设置订阅成功后是否mute mic
    ///@param mute 是否禁掉mic  true：禁止 false:否
    ///@return 0 succ
    virtual int muteRomoteMicBeforeSub(bool mute) = 0;
    
    ///设置编码发送视频质量
    ///@param profile 分辨率
    ///@param videoconfig video配置
    virtual void setVideoProfile(ePRTCVideoProfile profile,
                                 tPRTCVideoConfig& videoconfig) = 0;
    
    ///设置采集渲染视频分辨率
    ///@param profile 分辨率
    ///@param videoconfig video配置
    virtual void setVideoCaptureProfile(ePRTCVideoProfile profile) = 0;
    
    ///切换摄像头
    ///@param info 设备信息
    ///@return 0 succ
    virtual int switchCamera(tPRTCDeviceInfo& info) = 0;
    
    ///开关本地视频采集
    ///@param enable 开启关闭本地视频采集
    ///@return 0 succ
    virtual int enableLocalCamera(bool enable) = 0;
    
    ///发布
    ///@param type 媒体类型 摄像头或者桌面
    ///@param hasvideo 是否带视频
    ///@param hasaudio 是否带音频
    ///@return 0 succ
    virtual int publish(ePRTCMeidaType type,
                        bool hasvideo,
                        bool hasaudio) = 0;
    
    ///取消发布
    ///@param type 媒体类型
    ///@return 0 succ
    virtual int unPublish(ePRTCMeidaType type) = 0;
    
    ///开始预览
    ///@param view 预览的veiw信息
    ///@return 0 succ
    virtual int startPreview(tPRTCVideoCanvas& view) = 0;
    
    ///停止预览
    ///@param view 预览的veiw信息
    ///@return 0 succ
    virtual int stopPreview(tPRTCVideoCanvas& view) = 0;
    
    /// mute本地麦克
    ///@param mute true:是 false:否
    ///@return 0 succ
    virtual int muteLocalMic(
        bool mute,
        ePRTCMeidaType streamtype = PRTC_MEDIATYPE_VIDEO) = 0;
    
    /// mute本地视频
    ///@param mute true:是 false:否
    ///@param streamtype 媒体类型
    ///@return 0 succ
    virtual int muteLocalVideo(bool mute, ePRTCMeidaType streamtype) = 0;
    
    ///订阅
    ///@param info:订阅的流
    ///@return 0 succ
    virtual int subscribe(tPRTCStreamInfo& info) = 0;
    
    ///取消订阅
    ///@param info:取消订阅的流
    ///@return 0 succ
    virtual int unSubscribe(tPRTCStreamInfo& info) = 0;
    
    ///开启远端渲染
    ///@param view:开启远端渲染的视图信息
    ///@return 0 succ
    virtual int startRemoteView(tPRTCVideoCanvas& view) = 0;
    
    ///停止远端渲染
    ///@param view:视图信息
    ///@return 0 succ
    virtual int stopRemoteView(tPRTCVideoCanvas& view) = 0;
    
    /// mute远端音频
    ///@param info:mute流信息
    ///@param info:mute true:是 false:否
    ///@return 0 succ
    virtual int muteRemoteAudio(tPRTCMuteSt& info, bool mute) = 0;
    
    /// mute 远端视频
    ///@param info:mute流信息
    ///@param info:mute true:是 false:否
    ///@return 0 succ
    virtual int muteRemoteVideo(tPRTCMuteSt& info, bool mute) = 0;
    
    ///是否开启播放
    ///@param enable true:是 false:否
    ///@return 0 succ
    virtual int enableAllAudioPlay(bool enable) = 0;
    
    ///开始录制
    ///@param recordconfig 录制配置
    ///@return 0 succ
    virtual int startRecord(tPRTCRecordConfig& recordconfig) = 0;
    
    ///停止录制
    ///@return 0 succ
    virtual int stopRecord() = 0;
    
    ///设置摄像头是否开启
    ///@param enable true:是 false:否
    ///@return 0 succ
    virtual int configLocalCameraPublish(bool enable) = 0;
    
    ///本地摄像头是否开启
    ///@return true false
    virtual bool isLocalCameraPublishEnabled() = 0;
    
    ///设置分享桌面开启
    ///@param enable true:是 false:否
    ///@return 0 succ
    virtual int configLocalScreenPublish(bool enable) = 0;
    
    ///分享桌面是否开启
    ///@return true false
    virtual bool isLocalScreenPublishEnabled() = 0;
    
    ///配置本地音频发布
    ///@param enable true:是 false:否
    ///@return 0 succ
    virtual int configLocalAudioPublish(bool enable) = 0;
    
    ///本地发布是否禁止
    ///@return true false
    virtual bool isLocalAudioPublishEnabled() = 0;
    
    ///是否自动发布
    ///@return true false
    virtual bool isAutoPublish() = 0;
    
    ///是否自动订阅
    ///@return true false
    virtual bool isAutoSubscribe() = 0;
    
    ///是否纯音频
    ///@return true false
    virtual bool isAudioOnly() = 0;
    
    ///旁路推流
    ///@param url cdn地址
    ///@param config 转推配置(note:
    ///初始模板会自动选择mlayouts[0]，布局列表最大支持3种在房间内切换)
    ///@return 0 succ
    virtual int addPublishStreamUrl(const char* url,
                                    tPRTCTranscodeConfig* config) = 0;
    
    ///更新转推设置
    ///@param url cdn 地址
    ///@param 转推更新设置
    ///@return 0 succ
    virtual int updateTranscodeConfig(const char* url,
                                      tPRTCTranscodeConfig* config) = 0;
    
    ///停止旁路推流
    ///@param url cdn地址
    ///@return 0 succ
    virtual int removePublishStreamUrl(const char* url) = 0;
    
    ///更新旁路推流合流的流
    ///@param cmd rtmp操作类型
    ///@param streams 转推的流类型
    ///@param streams 转推的流长度
    ///@return 0 succ
    virtual int updateRtmpMixStream(ePRTCRtmpOpration cmd,
                                    tPRTCRelayStream* streams,
                                    int length) = 0;
    
    ///设置mute后的水印图 yuv420格式 内部自动缩放
    ///@param rgb格式的字节数组
    ///@param 长度
    ///@return 0 succ
    virtual int setMuteBackImage(const unsigned char* image,
                                 const int width,
                                 const int height) = 0;
    
    ///开启系统采集音
    ///@param enabe true:开启 fasle:关闭
    ///@return 0 succ
    virtual int enableCapturePlayBack(bool enable) = 0;
    
    ///推送一帧外部采集的视频数据给SDK
    ///@param video 视频数据
    ///@return 0 succ
    virtual int pushVideoFrameData(tPRTCVideoFrame* video) = 0;
    
    ///推送一帧外部采集的音频数据给SDK
    ///@param audio 视频数据
    ///@return 0 succ
    virtual int pushAudioFrameData(tPRTCAudioFrame* audio) = 0;
    
    ///设置外部采集数据的获取方式
    ///@param mode  IPRTC_EMDM_PUSH：推送数据给sdk   IPRTC_EMDM_PULL：SDK拉数据
    ///@return 0 succ
    virtual int SetExtendMediaDataMode(ePRTCExtendMediaDataMode mode) = 0;
    
    ///设置音频的编码属性
    ///@param audio_profile  IPRTC_Audio_Profile_Default：普通语音交流
    /// IPRTC_Audio_Profile_Music ：音乐模式
    ///@return 0 succ
    virtual int setAudioProfile(ePRTCAudioProfile audio_profile) = 0;
    
    ///设置SEI携带的数据，只有H264编码才支持SEI包
    ///@param data  SEI携带的数据
    ///@param data_size  数据长度,数据最大长度1024
    ///@return 0 succ
    virtual int setSEIData(unsigned char* data, int data_size) = 0;
    
    ///切换扬声器
    ///@param in info 设备信息
    ///@return 0 succ
    virtual int switchSpeaker(tPRTCDeviceInfo& info) = 0;

 protected:
    virtual ~IPRTCEngine() {}
};

#endif
