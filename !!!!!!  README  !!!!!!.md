License
--------
The MIT License (MIT)

Copyright (c) <2013> <Jake Horsfield>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

编译命令： g++ -Ic:/SFML/include *.cpp -Lc:/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

主程序： a.exe

说明文档：在已有贪食蛇游戏的基础上，增加如下功能：
1) 贪食蛇的控制
源代码只支持贪食蛇按4 个方向的运行，增加通过鼠标控制贪食蛇运动的方式。
当按下鼠标键时，设置一个方向向量，该方向向量为鼠标所在位置 (MousePosition)与
蛇头所在位置(SnakePosition)的差值：特别注意，当这两个向量差值为0 时，此次操作无效。
下一时刻，贪食蛇按该向量的方向运动；运动的距离为1 个标准单位。

实现方式：
找出鼠标对应窗口的位置，记录和蛇头位置的差值，并单位化为一个向量direcion_。
调用move函数，让蛇向direcion_方向移动。
同时重写keyboard对应的direction_函数，归一化move函数。


2）水果的控制
源代码只支持1 种水果，颜色随机且贪食蛇增加的长度固定。现增加黑色、棕色、红、
蓝色、绿色的水果，共5 种。其中贪食蛇吃了黑色、棕色水果，不增加其长度；吃了红色、
蓝色、绿色水果，贪食蛇的长度分别增加3、2、1；增加的长度在贪食蛇的尾部。
系统随机生成上述 5 种水果，保持黑色和褐色水果所占比例为25%，其他的占75%。

实现方式：
使用随机数产生颜色不同的水果，通过余数控制它们产生的比例（在小规模情况下可能比例不对）。
增加水果的属性记录颜色，调用grow函数多次实现长不同长度。

3）绘制精灵版本的贪食蛇
源代码中的贪食蛇绘制过于简单：使用矩形绘制，没有眼睛也没有方向。要求更改贪食
蛇的绘制，头部使用图片，通过sprite 进行绘制，其余部分使用园叠加黑色的矩形块绘制，
整体效果如下图。

实现方式：
头部从蛇的身体中单独列出来。然后使用sprite绘制。
蛇的身体也使用了sprite绘制

4）整体界面的修改
允许修改背景的颜色（提供白色、黑色、褐色三种）；允许显示（或关闭）网格。

实现方式：
按tab键切换背景，按space键开启/关闭网格。
背景使用rectangleshape通过图片进行渲染，通过记录tab键按下次数进行切换。
网格使用VertaxArray进行绘制，通过记录space按下次数进行开关。

5） 增加了MenuScreen和GameoverScreen的背景图片，同样使用rectangleshape通过图片进行渲染

6） 修改了MenuScreen和GameoverScreen的字体

7） 修改了游戏bgm