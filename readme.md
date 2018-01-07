
##YdarWallpaper 

### 由 GLSL_Render_BackGround 改名,这个名字太难听了

## glsl 渲染的动态桌面壁纸

	1.现在实现在 win7 桌面图标后面绘图(之后的版本我测试了几台电脑都可以,但是win7 表现不一,与AERO有关). 需要的可以去  WallpaperUtils 中查看 .
	2.使用opengl glsl Frag 进行 渲染, 想法来自于"Glsl Sandbox"
	3.考完研了,重在参与了,代码重写了.比以前好多了,但是有些重度依赖QT
	4.渲染基本是使用 QT的opengl的库和 freeglut 等
	5.代码是 QT5 + VS2015 编写的
## 几个效果图 ,glsl代码均来自"Glsl Sandbox"

### [demo下载](https://github.com/ydar95/YdarWallpaper/releases)

### 软件界面

![1](https://github.com/ydar95/GLSL_Render_BackGround/raw/master/readme_data/1.png)



### 下面是我从GLSL 中选的一些 Frag 代码.

![2](https://github.com/ydar95/GLSL_Render_BackGround/raw/master/readme_data/2.png)
![3](https://github.com/ydar95/GLSL_Render_BackGround/raw/master/readme_data/3.png)
![4](https://github.com/ydar95/GLSL_Render_BackGround/raw/master/readme_data/4.png)
![5](https://github.com/ydar95/GLSL_Render_BackGround/raw/master/readme_data/5.png)



### 由于录制的原始文件过大,我只好删掉一些帧,来降低体积.gif动画比较顿卡, 真正渲染的流畅度与GLSL代码和你的显卡有关.

![gif1](https://github.com/ydar95/GLSL_Render_BackGround/raw/master/readme_data/display.gif)


祝大家新年快乐.
现在又要忙实验室的项目了,各种更新是不定期的.希望大家帮忙加个星星
time: 2018年1月8日 02:56:01