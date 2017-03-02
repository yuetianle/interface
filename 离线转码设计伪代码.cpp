
/*******************************************获取token****************************************************/
//获取URL
http://xxx:xx/token
//返回信息
{"result":"1/errno" , "token":"65ebdff62adf92ad8bb995192660737f"}


/********************************************登陆**************************************************/
http://xxx:xx/user?operation=login&token=65ebdff62adf92ad8bb995192660737e&username=xxxx&password=xxxx
/*
    参数简介：
    token           //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证
    username        //用户名，明文
    password        //密码，为MD5(token+password) 的值，注意没有中间的+号

    返回信息
    {"result":"1/errno"}
*/
修改为
/********************************************登陆**************************************************/
http://xxx:xx/login?operation=login&token=65ebdff62adf92ad8bb995192660737e&username=xxxx&password=xxxx
/*
    参数简介：
    token           //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证
    username        //用户名，明文
    password        //密码，为MD5(token+password) 的值，注意没有中间的+号

    返回信息
    {"result":"1/errno", "token:":"UUID-用于后续的操作"}
*/


/********************************************增加用户**************************************************/
http://xxx:xx/user?operation=add&token=65ebdff62adf92ad8bb995192660737e&username=xxxx&password=xxxx
/*
    参数简介：
    token           //鉴权处理，登陆之前需要获取一个token，用于和超时验证
    username        //用户名，明文
    password        //密码，为MD5(token+password) 的值，注意没有中间的+号

    返回信息
    {"result":"1/errno"}
*/

/********************************************设备组管理*******************************************************/
//增加
http://xxx:xx/trans_group?operation=add&token=65ebdff62adf92ad8bb995192660737e&name=group1
/*
    参数简介：
    token           //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证
    name            //设备组名称（服务器会校验重复），如果重复，返回失败

    //id            //设备组ID（唯一）（服务器会校验重复），如果重复，返回失败    
    返回信息
    {"result":"1/errno"}
*/

//删除
http://xxx:xx/trans_group&operation=del&token=65ebdff62adf92ad8bb995192660737e&id=123
/*
    参数简介：
    token           //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证
    name            //设备组ID（唯一）

    返回信息
    {"result":"1/errno"}
*/

//修改
http://xxx:xx/trans_group?operation=update&token=65ebdff62adf92ad8bb995192660737e&id=123&name=group2
/*
    参数简介：
    token           //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证
    //id              //设备组ID（唯一）,不能改变
    name            //name为被修改的值
    返回信息
    {"result":"1/errno"}
*/

//查询
http://xxx:xx/trans_group?operation=query&token=65ebdff62adf92ad8bb995192660737e
/*
    参数简介：
    token           //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证

    返回信息
    {
        "result":"0/1",
        "trans_groups":[
            {
                //"id":"1",
                "name":"group1"
            },
            {
                //"id":"2",
                "name":"group2"
            }
        ]
    }

    返回信息简介：
    name            //返回设备组的名称
    trans_groups    //所有的设备信息
*/


/********************************************设备管理*******************************************************/
//增加
http://xxx:xx/trans?operation=add&token=65ebdff62adf92ad8bb995192660737e&id=xxx&name=trans1&ip=192.168.1.123&trans_group=name
/*
    参数简介：
	
    token           //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证
    //id            //设备ID（是唯一的,服务器会校验重复），如果重复，返回失败
    name            //设备名称（是唯一的，服务器会校验重复），如果重复，返回失败
    ip              //设备的IP地址，应该是唯一的
    trans_group     //设备所属的设备组，应该从设备现有的设备组中选取
    注：请求类型可以为一对参数，也可以为所有的参数，此处没有限制，即如下几种情况都可行：
    	http://xxx:xx/trans?operation=add&token=65ebdff62adf92ad8bb995192660737e&id=123
    	http://xxx:xx/trans?operation=add&token=65ebdff62adf92ad8bb995192660737e&id=123&name=trans1
    	http://xxx:xx/trans?operation=add&token=65ebdff62adf92ad8bb995192660737e&id=123&name=trans1&ip=192.168.1.123
    	http://xxx:xx/trans?operation=add&token=65ebdff62adf92ad8bb995192660737e&id=123&name=trans1&ip=192.168.1.123&trans_group=name

    返回信息
    {"result":"1/errno","state":"1/0","online":"online"}

    返回信息简介：
    result          //增加的状态，1表示成功，errno表示返回的错误码
    state           //表示设备是否启用 1表示启用，0表示未启用
    online          //表示设备是否在线，此处是通过IP地址与设备服务器通过心跳的方式获取设备是否在线，是否有该设备
*/

//删除
http://xxx:xx/trans?operation=del&token=65ebdff62adf92ad8bb995192660737e&id=123
/*
    参数简介：
    token           //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证
    //id              //设备ID
    name

    返回信息：
    {"result":"1/errno"}
*/

//修改
http://xxx:xx/trans?operation=update&token=65ebdff62adf92ad8bb995192660737e&id=123&name=trans2&ip=192.168.1.124&trans_group=id1
/*
    参数简介：
    token           //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证
    //id              //设备ID（是唯一的,服务器会校验重复），如果重复，返回失败
    name            //设备名称（是唯一的，服务器会校验重复），如果重复，返回失败
    ip              //设备的IP地址，应该是唯一的
    trans_group     //设备所属的设备组，应该从设备现有的设备组中选取
    注：请求类型可以为一对参数，也可以为所有的参数，此处没有限制

    返回信息
    {"result":"1/errno","state":"1/0","online":"online"}

    返回信息简介：
    result          //增加的状态，1表示成功，errno表示返回的错误码
    state           //表示设备是否启用 1表示启用，0表示未启用
    online          //表示设备是否在线，此处是通过IP地址与设备服务器通过心跳的方式获取设备是否在线，是否有该设备
*/

//查询
http://xxx:xx/trans?operation=query&token=65ebdff62adf92ad8bb995192660737e
/*
    参数简介：
    token           //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证

    返回信息：
    {
        "result":"0/1",
        "all_trans":[
            {
                "id":"1",
                "name":"trans1",
                "ip":"192.168.1.2",
                "trans_group":"1",
                "state":"0",
                "online":"1"
            },
            {
                "id":"2",
                "name":"trans2",
                "ip":"192.168.1.3",
                "trans_group":"2",
                "state":"1",
                "online":"1"
            }
        ]
    }

    返回信息简介：
    result          //增加的状态，1表示成功，errno表示返回的错误码
    all_trans       //所有的设备信息
*/

//单独状态查询，用于查询某个ID的在线状态和启用状态
http://xxx:xx/trans?operation=query&token=65ebdff62adf92ad8bb995192660737e&id=1
/*
    参数简介：
    token           //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证
    id              //设备ID

    返回信息：
    {"result":"0/1" , "state":"1/0" , "online":"1/0"}
*/

//启用
http://xxx:xx/trans?operation=start&token=65ebdff62adf92ad8bb995192660737e&id=1
/*
    参数简介：
    token           //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证
    id              //设备ID

    返回信息：
    {"result":"1/errno","state":"1/0"}
*/

//停用
http://xxx:xx/trans?operation=stop&token=65ebdff62adf92ad8bb995192660737e&id=1
/*
    参数简介：
    token           //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证
    id              //设备ID

    返回信息：
    {"result":"1/errno","state":"1/0"}
*/

//关机
http://xxx:xx/trans?operation=shutdown&token=65ebdff62adf92ad8bb995192660737e&id=1
/*
    参数简介：
    token           //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证
    id              //设备ID

    返回信息：
    {"result":"1/errno"}
*/

/********************************************存储服务器管理*******************************************************/
//增加
http://xxx:xx/storage?operation=add&token=65ebdff62adf92ad8bb995192660737e&id=123&name=trans1&type=nfs&ip=192.168.1.21&port=21&username=admin&password=**xx**&encode_type=xxx
/*
    参数简介：
    token           //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证
    id              //存储服务器设备ID（唯一）
    name            //存储服务器名字（唯一）
    type            //存储服务器的类型，目前支持三种（NFS，FTP，samba）三种存储类型
    ip              //存储服务器IP
    port            //存储服务器端口
    username        //存储服务器用户名
    password        //存储服务器密码（base64(token+password))方式加密

    注：请求类型可以为一对参数，也可以为所有的参数，此处没有限制

    //返回信息：
    {"result":"0/errno"}
*/

//删除
http://xxx:xx/storage?operation=del&token=65ebdff62adf92ad8bb995192660737e&id=123
/*
    参数简介：
    token           //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证
    id              //存储服务器设备ID（唯一）

    //返回信息：
    {"result":"0/errno"}
*/

//修改
http://xxx:xx/storage?operation=update&token=65ebdff62adf92ad8bb995192660737e&id=123&name=trans1&type=nfs&ip=192.168.1.21&port=21&username=admin&password=**xx**&encode_type=xxx
/*
    参数简介：
    token           //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证
    id              //存储服务器设备ID（唯一）
    name            //存储服务器名字（唯一）
    type            //存储服务器的类型，目前支持三种（NFS，FTP，samba）三种存储类型
    ip              //存储服务器IP
    port            //存储服务器端口
    username        //存储服务器用户名
    password        //存储服务器密码（base64(token+password))方式加密

    注：请求类型可以为一对参数，也可以为所有的参数，此处没有限制

    //返回信息：
    {"result":"0/errno"}
*/

//查询
http://xxx:xx/storage?operation=query&token=65ebdff62adf92ad8bb995192660737e

/*
    参数简介：
    token           //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证

    state           //运行状态

    //返回信息：
    {
        "result":"0/1",
        "storages":[
            {
                "id":"1",
                "name":"storage1",
                "type":"nfs",
                "ip":"192.168.1.2",
                "port":"80",
                "username":"easyhao",
                "password":"xxxx"
            },
            {
                "id":"2",
                "name":"storage2",
                "type":"nfs",
                "ip":"192.168.1.3",
                "port":"80",
                "username":"easyhao",
                "password":"xxxx1"
            }
        ]
    }
*/

//启用
http://xxx:xx/storage?operation=start&token=65ebdff62adf92ad8bb995192660737e&id=123
/*
    参数简介：
    token           //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证
    id              //存储服务器设备ID（唯一）

    返回信息：
    {"result":"0/1","state":"1/0"}
    
    返回信息简介：
    state           //1 表示启用  0 表示未启用
*/


//停止
http://xxx:xx/storage?operation=stop&token=65ebdff62adf92ad8bb995192660737e&id=123
/*
    参数简介：
    token           //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证
    id              //存储服务器设备ID（唯一）

    返回信息：
    {"result":"0/1","state":"1/0"}
    
    返回信息简介：
    state           //1 表示启用  0 表示未启用
*/

//查询当前服务启用状态
http://xxx:xx/storage?operation=query&token=65ebdff62adf92ad8bb995192660737e&id=1
/*
    参数简介：
    token           //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证
    id              //存储服务器设备ID（唯一）

    返回信息：
    {"result":"0/1","state":"1/0"}
    
    返回信息简介：
    state           //1 表示启用  0 表示未启用
*/

/********************************************编码参数信息*******************************************************/
template
{
	id 						//参数模板的ID
	name 					//参数模板的名字

    out_fmt                 //输出格式(ts/mp4/flv/mp3)
    no_video                //是否去掉视频（1 去掉 0 不去）
    no_audio                //是否去掉音频（1 去掉 0 不去）

    videocodec              //编码格式 h264/h265
    level                   //264(baseline , main , high , high444p) 265(main , main10 , rext)
    videobitrate            //码率（单位为Kbps）
    width                   //视频宽度[128 - 4096]
    height                  //视频宽度[128 - 4096]
    fps                     //视频帧率[0 - 60]
    preset                  //264(default , slow , fast) 265(slow , medium , fast)
    gop                     //关键帧间最大帧数 [1 - 100000]
    buffer_size             //缓冲区大小,单位kb[1000 - 128000]
    cbr 					//是否CBR，1 是， 0 否
	minrate                 //视频码率范围下限,单位Kbps
	maxrate                 //视频码率范围上限,单位Kbps

    audio_codec             //aac mp3 
    simplerate              //22050 , 32000 , 44100 , 48000 , 96000
    channels                //aac(1 , 2 , 3 , 4 , 5 , 6 , 7 , 8)，mp3 只有（1,2）
    audiobitrate            //码率,单位Kbps
}

if(no_video == 1)
{
	//如下选项都未不可编辑状态
	videocodec              //编码格式 h264/h265
    level                   //264(baseline , main , high , high444p) 265(main , main10 , rext)
    videobitrate            //码率（单位为Kbps）
    width                   //视频宽度[128 - 4096]
    height                  //视频宽度[128 - 4096]
    fps                     //视频帧率[0 - 60]
    preset                  //264(default , slow , fast) 265(slow , medium , fast)
    gop                     //关键帧间最大帧数 [1 - 100000]
    buffer_size             //缓冲区大小,单位kb[1000 - 128000]
    cbr 					//是否CBR，1 是， 0 否
	minrate                 //视频码率范围下限,单位Kbps
	maxrate                 //视频码率范围上限,单位Kbps
}

if (no_audio == 1)
{
	//如下选项都未不可编辑状态
	audio_codec             //aac mp3 
	simplerate              //22050 , 32000 , 44100 , 48000 , 96000
	channels                //aac(1 , 2 , 3 , 4 , 5 , 6 , 7 , 8)，mp3 只有（1,2）
	audiobitrate            //码率,单位Kbps
}

if(cbr == 1)
{
	//如下两个选项可以编辑
	minrate                 //视频码率范围下限,单位Kbps
    maxrate                 //视频码率范围上限,单位Kbps
}
else
{
	//这两个选择性不可编辑
	minrate                 //视频码率范围下限,单位Kbps
    maxrate                 //视频码率范围上限,单位Kbps
}


//增加参数模板
http://xxx:xx/template?operation=add&token=65ebdff62adf92ad8bb995192660737e&id=1&name=hevc_cbr_xxx& ... &audiobitrate=xxx
/*
	参数简介：
	token           		//鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证
	id 						//参数模板的ID
	name 					//参数模板的名字

    out_fmt                 //输出格式(ts/mp4/flv/mp3)
    no_video                //是否去掉视频（1 去掉 0 不去）
    no_audio                //是否去掉音频（1 去掉 0 不去）

    videocodec              //编码格式 h264/h265
    level                   //264(baseline , main , high , high444p) 265(main , main10 , rext)
    videobitrate            //码率（单位为Kbps）
    width                   //视频宽度[128 - 4096]
    height                  //视频宽度[128 - 4096]
    fps                     //视频帧率[0 - 60]
    preset                  //264(default , slow , fast) 265(slow , medium , fast)
    gop                     //关键帧间最大帧数 [1 - 100000]
    buffer_size             //缓冲区大小,单位kb[1000 - 128000]
    cbr 					//是否CBR，1 是， 0 否
	minrate                 //视频码率范围下限,单位Kbps
	maxrate                 //视频码率范围上限,单位Kbps

    audio_codec             //aac mp3 
    simplerate              //22050 , 32000 , 44100 , 48000 , 96000
    channels                //aac(1 , 2 , 3 , 4 , 5 , 6 , 7 , 8)，mp3 只有（1,2）
    audiobitrate            //码率,单位Kbps

	注：请求类型可以为一对参数，也可以为所有的参数，此处没有限制

	返回信息：
    {"result":"1/errno"}
*/

//删除模板
http://xxx:xx/template?operation=add&token=65ebdff62adf92ad8bb995192660737e&id=1
/*
    参数简介：
    token                   //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证
    id                      //参数模板的ID

    返回信息：
    {"result":"1/errno"}
*/

//修改模板
http://xxx:xx/template?operation=update&token=65ebdff62adf92ad8bb995192660737e&id=1&name=temp1& ...=... &audiobitrate=128
/*
	参数简介：
	token           		//鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证
	id 						//参数模板的ID
	name 					//参数模板的名字

    out_fmt                 //输出格式(ts/mp4/flv/mp3)
    no_video                //是否去掉视频（1 去掉 0 不去）
    no_audio                //是否去掉音频（1 去掉 0 不去）

    videocodec              //编码格式 h264/h265
    level                   //264(baseline , main , high , high444p) 265(main , main10 , rext)
    videobitrate            //码率（单位为Kbps）
    width                   //视频宽度[128 - 4096]
    height                  //视频宽度[128 - 4096]
    fps                     //视频帧率[0 - 60]
    preset                  //264(default , slow , fast) 265(slow , medium , fast)
    gop                     //关键帧间最大帧数 [1 - 100000]
    buffer_size             //缓冲区大小,单位kb[1000 - 128000]
    cbr 					//是否CBR，1 是， 0 否
	minrate                 //视频码率范围下限,单位Kbps
	maxrate                 //视频码率范围上限,单位Kbps

    audio_codec             //aac mp3 
    simplerate              //22050 , 32000 , 44100 , 48000 , 96000
    channels                //aac(1 , 2 , 3 , 4 , 5 , 6 , 7 , 8)，mp3 只有（1,2）
    audiobitrate            //码率,单位Kbps

	注：请求类型可以为一对参数，也可以为所有的参数，此处没有限制

	返回信息：
    {"result":"1/errno"}
*/

//查询模板
http://xxx:xx/template?operation=query&token=65ebdff62adf92ad8bb995192660737e
/*
    参数简介：
    token                   //鉴权处理，登陆之前需要获取一个token，用于加密密码和超时验证

    返回信息：
    {
        "result":"1/errno",
        "templates":[
            {
                "id":"100",
                "name":"template1",
                "out_fmt":"mp4",
                "no_video":"0",
                "no_audio":"0",
                "videocodec":"h264",
                "level":"baseline",
                "videobitrate":"4096",
                "width":"1920",
                "height":"1080",
                "fps":"24",
                "preset":"default",
                "gop":"25",
                "buffer_size":"3000",
                "cbr":"1",
                "minrate":"",
                "maxrate":"",
                "audio_codec":"aac",
                "simplerate":"22050",
                "channels":"2",
                "audiobitrate":"128"
            }
        ]
    }
*/

/********************************************任务队列管理*******************************************************/
task_queue
{
    id,                 //任务队列的ID
    name,               //任务队列的名称
    trans_group_id      //设备组ID（唯一）
}
//添加转码任务队列
http://xxx:xx/task_queue?operation=add&token=65ebdff62adf92ad8bb995192660737e&id=101&name=task_queue1&trans_group_id=xxx
/*
    返回信息：
    {"result":"1\errno"}
*/

//删除转码任务队列
http://xxx:xx/task_queue?operation=del&token=65ebdff62adf92ad8bb995192660737e&id=101
/*
    返回信息：
    {"result":"1\errno"}
*/

//修改转码任务队列
http://xxx:xx/task_queue?operation=update&token=65ebdff62adf92ad8bb995192660737e&id=101&name=xxx&trans_group_id=xxx
/*
    返回信息：
    {"result":"1\errno"}
*/

//查询转码任务队列
http://xxx:xx/task_queue?operation=query&token=65ebdff62adf92ad8bb995192660737e
/*
    返回信息：
    {
        "result":"1\errno",
        "task_queue":[
            {
                "id":"001",
                "name":"group1",
                "trans_group_id":"002"
            }
        ]
    }
*/
    

/********************************************任务管理*******************************************************/
task
{
    id,                 //任务ID
    name,               //任务名称
    type,               //任务类型(0 - 自动扫描文件夹 ; 1 - 单文件转码)
    input_file,         //输入文件(如果是单文件转码，给此处赋值)
    input_folder,       //输入文件夹(如果是自动扫描文件夹，给此处赋值)
    task_queue_id,		//任务队列的ID
    output_file,		//输出文件(如果是单文件转码，给此处赋值)
    output_folder,		//输出文件夹(如果是自动扫描文件夹，给此处赋值)
    task_priority,		//任务优先级(1 2 3 4 5 - 1最高 3正常 5最低),默认给3
    template_id,	    //转码参数模板ID
    state               //0 未开始 1 等待 2 开始 3 完成
}

//增加任务
http://xxx:xx/task?operation=add&token=65ebdff62adf92ad8bb995192660737e&id=101&name=task1&type=0&input_folder=xxx&output_folder=xxx&task_priority=3&template_id=10&task_queue_id=001
/*
    参数简介：
        如上task标签内的介绍
    
    注：请求类型可以为一对参数，也可以为所有的参数，此处没有限制
    返回信息：
    {"result":"1/errno"}
*/

//删除任务
http://xxx:xx/task?operation=del&token=65ebdff62adf92ad8bb995192660737e&id=101
/*
    返回信息：
    {"result":"1/errno"}
*/

//修改任务（注：任务启动之后不可以修改）
http://xxx:xx/task?operation=update&token=65ebdff62adf92ad8bb995192660737e&id=101&name=task1&type=0&input_folder=xxx&output_folder=xxx&task_priority=3&template_id=10
/*
    参数简介：
        如上task标签内的介绍
    
    注：请求类型可以为一对参数，也可以为所有的参数，此处没有限制
    返回信息：
    {"result":"1/errno"}
*/

//查询任务
http://xxx:xx/task?operation=query&token=65ebdff62adf92ad8bb995192660737e
/*

    返回信息：
    {
        "result":"1/errno",
        "tasks":[
            {
                "id":"101",
                "name":"task1",
                "type":"0",
                "input_folder":"xxxxxxx",
                "trans_server":"auto",
                "output_folder":"xxxxxxx",
                "task_priority":"3",
                "template_id":"101",
                "state":"0"               
            }
        ]
    }
*/



--错误码
{
	0							success
	100001				数据库连接失败
}