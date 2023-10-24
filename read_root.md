# Inpac终端读取.root
以查看/lustre/neutrino/wangyingwei/data/shower/10_100TeV/batch0/detectorResponse/data.root  目录文件为例
1.转到目录：
`cd /lustre/neutrino/wangyingwei/data/shower/10_100TeV/batch0/detectorResponse`
2.查看root文件数据结构：
`root -l data.root
.ls`
可以看到root文件中包含各种Tree
以DomHit为例，查看Branch：
`DomHit->Print()`
临时查看数据内容：
`DomHit->Scan()`

退出root交互界面：
`.q`

3）脚本读取root
以读取root中的DomHit 内容为例
使用`code test.cpp` 命令可查看目录中的test.cpp 脚本代码，可修改读取文件地址及指定读取数据内容等，Ctrl + S 或 Cmd + S 保存修改后的代码

运行目录中的test.cpp脚本：
`root -l test.cpp `

输出文件默认保存在该目录domhit_data.txt
查看txt内容：
`cat domhit_data.txt`

使用cp命令复制脚本到你的root文件目录：
`cp -r /lustre/neutrino/wangyingwei/data/shower/10_100TeV/batch0/detectorResponse/test.cpp your/data/path`


