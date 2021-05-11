#ifndef _PRTC_ERROR_CODE_H_
#define _PRTC_ERROR_CODE_H_

typedef enum {
	PRTC_CALLBACK_ERR_CODE_OK = 0,
	PRTC_CALLBACK_ERR_SERVER_CON_FAIL = 5000, //����������ʧ��
	PRTC_CALLBACK_ERR_INVAILDSTATE, // ��������ӶϿ�
	PRTC_CALLBACK_ERR_INVAILDPARAMETER, // ��Ч����
	PRTC_CALLBACK_ERR_SERVER_DIS, // ��������ӶϿ�
	PRTC_CALLBACK_ERR_SAME_CMD,  //�ظ��ĵ���
	PRTC_CALLBACK_ERR_NOT_IN_ROOM, //δ���뷿�� �޷����в��� 
	PRTC_CALLBACK_ERR_ROOM_JOINED, // �Ѽ��뷿�� �������
	PRTC_CALLBACK_ERR_SDK_INNER,   // SDK �ڲ�����
	PRTC_CALLBACK_ERR_ROOM_RECONNECTING, // ������ �����޷�Ͷ��      
	PRTC_CALLBACK_ERR_STREAM_PUBED,  // ���Ѿ�����  ���跢��
	PRTC_CALLBACK_ERR_PUB_NO_DEV,  // �����޿��� ��Ƶ ��Ƶ�豸
	PRTC_CALLBACK_ERR_STREAM_NOT_PUB, //��û�з��� �޷��������в���
	PRTC_CALLBACK_ERR_STREAM_SUBED,  //���Ѿ�����  ���趩��
	PRTC_CALLBACK_ERR_STREAM_NO_SUB, //��û�ж���  �޷�
	PRTC_CALLBACK_ERR_SUB_NO_USER,   //�޶�Ӧ���û� �޷�����
	PRTC_CALLBACK_ERR_SUB_NO_STREAM,  // �޶�Ӧ��ý����
	PRTC_CALLBACK_ERR_USER_LEAVING, // �û������뿪����  �޷�������������
	PRTC_CALLBACK_ERR_NO_HAS_TRACK,  //�޶�Ӧ��ý����
	PRTC_CALLBACK_ERR_MSG_TIMEOUT, // ��Ϣ����ʱ
	PRTC_CALLBACK_ERR_MSG_RECORDSTART, //¼���ѿ���
	PRTC_CALLBACK_ERR_MSG_RELAYSTART,  //ת���ѿ���
	PRTC_CALLBACK_ERR_MSG_RELAYURLNOTEXISTED, //ת�Ƶ�ַ������
	PRTC_CALLBACK_ERR_MSG_URLERROR,  //CDN��ַ��Ч
	PRTC_CALLBACK_ERR_MSG_NOSTREAMS, //����������
	PRTC_CALLBACK_ERR_MSG_VIDEODVICEERR, //��Ƶ�豸����
	PRTC_CALLBACK_ERR_MSG_RECORDDVICEERR, //mic ¼���豸����
} ePRTCCallbackErrCode;

typedef enum {
	PRTC_RETURN_ERR_CODE_OK = 0,
	PRTC_RETURN_ERR_AUTO_PUB = 1000, //�Զ�����
	PRTC_RETURN_ERR_AUTO_SUB, //�Զ�����
	PRTC_RETURN_ERR_NOT_INIT, //����û�г�ʼ��
	PRTC_RETURN_ERR_IN_ROOM, //�Ѿ����뷿��
	PRTC_RETURN_ERR_NOT_IN_ROOM, // δ���뷿��
	PRTC_RETURN_ERR_NOT_PUB_TRACK, //δ������Ӧý��
	PRTC_RETURN_ERR_INVAILED_PARGRAM,// ��Ч����
	PRTC_RETURN_ERR_INVAILED_WND_HANDLE,// ��Ч���ھ��
	PRTC_RETURN_ERR_INVAILED_MEDIA_TYPE,// ��Чý������
	PRTC_RETURN_ERR_SUB_ONEMORE,// ���ٶ���һ��ý��
	PRTC_RETURN_ERR_NO_PUB_ROLE, //�޷���Ȩ��
	PRTC_RETURN_ERR_NO_SUB_ROLE, //�޶���Ȩ��
	PRTC_RETURN_ERR_CAM_NOT_ENABLE, //û�����ñ���cam ����
	PRTC_RETURN_ERR_SCREEN_NOT_ENABLE, //û�����ñ���screen ����
	PRTC_RETURN_ERR_AUDIO_MODE,        // ����Ƶģʽ
	PRTC_RETURN_ERR_SECKEY_INVALID ,    // seckey ��Ч
	PRTC_RETURN_ERR_INVAILD_FILEPATH,
	PRTC_RETURN_ERR_NOT_SUPORT_AUDIO_FORMAT,
    PRTC_RETURN_ERR_INVAILED_STATE,   //�ڲ�״̬����
    PRTC_RETURN_ERR_INVAILED_POINTER,   //ָ�����
    PRTC_RETURN_ERR_DROPPED,  //��֡
} ePRTCReturnErrCode;

#endif
