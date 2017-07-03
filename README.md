# morgon
morgon
姓名：张伯宁
学号：516030910319

morgon项目：
共有三个大部分：
A：client类————————声明在client.h里面
                   定义在client.cpp
                   功能：
                   getInfo():提示用户输入证券信息
                   generateFIX()：生成FIX协议
                   parseFIX():解析由server发过来的FIX协议
                   findOrder():用户查看订单的状态
          ***自定义：tag_pair：构成pair
                              用来储存tag含义以及
                              tag对应的内容
                  用map<int, tag_pair* >储存用户输入的证券信息
                  int 表示tag标号
                  tag_pair* 表示tag含义和内容。   

B:server类————————声明在server.h里面
                  定义在server.cpp
                  功能：
                  get_tags()：对由client发来的协议进行处理解析
                  match_order()：对订单或者卖单进行匹配
                                 分别对交易失败，partialfill，full进行反馈
                                 返回feedback{vector《int》}
                                 用数字标号表示匹配状态；
                  recipt():对match_order的反馈信息
                           重新编写FIX，
                          对原有的tag进行更改
                  setOrders():对订单或卖单信息进行记录
                              对订单匹配以及交易是否成功进行记录
                  generateFIX()：生成FIX协议（同client）
                  parseFIX():解析由server发过来的FIX协议（同client）
                  
C：main以及.cpp：—————————对client和server进行信息传递
                         
