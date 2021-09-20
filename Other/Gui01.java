import java.awt.*;
import java.awt.event.*;
import java.io.*;

public class Gui01 {
    private static String[] MenuAll = {"文件(F)", "编辑(E)", "帮助(H)"};
    private static String[][] MenuItemAll = {
            {"新建", "打开", "保存", "退出(X)"},
            {"剪切", "拷贝", "粘贴", "查找"},
            {"关于"}
    };
    private static Menu[] menus;
    private static TextArea textArea;

    public static void main(String[] args) {
        Frame frame = CreateFrom("记事本", 200, 200, 500, 500);
        Menu[] menus = CreateMenuBar(frame, MenuAll, MenuItemAll, Gui01.menus);
        SetAttributes(frame, menus, textArea);
    }

    public static Frame CreateFrom(String name, int x, int y, int width, int height) {
        Frame frame = new Frame(name);
        textArea = new TextArea();
        frame.setBounds(x, y, width, height);
        frame.setVisible(true);
        frame.setFont(new Font("隶书", 0, 12));
        textArea.setFont(new Font("隶书", 0, 17));
        frame.add(textArea);
        frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        return frame;
    }

    public static Menu[] CreateMenuBar(Frame frame, String[] MenuAll, String[][] MenuItemAll, Menu[] menus) {
        menus = new Menu[MenuAll.length];
        MenuBar menuBar = new MenuBar();
        for (int i = 0; i < MenuAll.length; i++) {
            menus[i] = new Menu(MenuAll[i]);
            for (int j = 0; j < MenuItemAll[i].length; j++) {
                MenuItem menuItem = new MenuItem(MenuItemAll[i][j]);
                menus[i].add(menuItem);
            }
            menuBar.add(menus[i]);
        }
        frame.setMenuBar(menuBar);
        return menus;
    }

    private static void SetAttributes(Frame frame, Menu[] menus, TextArea textArea) {
        final String[] cope = {""};
        final String[] status = {"无标题"};
        final String[] filename = new String[1];
        final String[] Directory = new String[1];
        final boolean[] isStart = {true};

        menus[0].getItem(0).setShortcut(new MenuShortcut(KeyEvent.VK_N));
        menus[0].getItem(1).setShortcut(new MenuShortcut(KeyEvent.VK_O));
        menus[0].getItem(2).setShortcut(new MenuShortcut(KeyEvent.VK_S));

        menus[1].getItem(0).setShortcut(new MenuShortcut(KeyEvent.VK_X));
        menus[1].getItem(1).setShortcut(new MenuShortcut(KeyEvent.VK_C));
        menus[1].getItem(2).setShortcut(new MenuShortcut(KeyEvent.VK_V));
        menus[1].getItem(3).setShortcut(new MenuShortcut(KeyEvent.VK_F));

        menus[0].getItem(0).addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                status[0] = "无标题";
                filename[0] = null;
                Directory[0] = null;
                isStart[0] = true;
                textArea.setText("");
                if (filename[0] != null) {
                    frame.setTitle(filename[0] + "-记事本");
                } else {
                    frame.setTitle(status[0] + "-记事本");
                }
            }
        });

        menus[0].getItem(1).addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                FileDialog fileDialog = new FileDialog(new Frame(), "文件选择", FileDialog.LOAD);
                fileDialog.setVisible(true);
                fileDialog.setMultipleMode(false);
                File[] files = fileDialog.getFiles();
                if (fileDialog.getFile() != null) {
                    filename[0] = fileDialog.getFile();
                    Directory[0] = fileDialog.getDirectory();
                    isStart[0] = false;
                    frame.setTitle(filename[0] + "-记事本");
                    textArea.setText("");
                    try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(files[0]), "GBK"))) {
                        String content;
                        while ((content = br.readLine()) != null) {
                            textArea.append(content + "\n");
                        }
                    } catch (IOException ex) {
                        ex.printStackTrace();
                    }
                }
            }
        });

        menus[0].getItem(2).addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (isStart[0]) {
                    FileDialog fileDialog = new FileDialog(new Frame(), "保存文件", FileDialog.SAVE);
                    fileDialog.setVisible(true);
                    fileDialog.setMultipleMode(false);
                    filename[0] = fileDialog.getFile();
                    Directory[0] = fileDialog.getDirectory();
                    if (fileDialog.getFile() != null) {
                        isStart[0] = false;
                    }
                }
	 if (filename[0] != null && Directory[0] != null) {
                    File file = new File(Directory[0] + "" + filename[0]);
                    try (BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(file), "UTF-8"))) {
                        bw.write(textArea.getText());
                    } catch (Exception ex) {
                        ex.printStackTrace();
                    }
                }
                if (filename[0] != null) {
                    frame.setTitle(filename[0] + "-记事本");
                } else {
                    frame.setTitle(status[0] + "-记事本");
                }
            }
        });

        menus[0].getItem(3).addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        menus[1].getItem(1).addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                cope[0] = textArea.getSelectedText();
            }
        });

        menus[1].getItem(2).addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textArea.insert(cope[0], textArea.getCaretPosition());
            }
        });

        textArea.addTextListener(new TextListener() {
            @Override
            public void textValueChanged(TextEvent e) {
                if (filename[0] != null) {
                    frame.setTitle("*" + filename[0] + "-记事本");
                } else {
                    frame.setTitle("*" + status[0] + "-记事本");
                }
            }
        });

        menus[1].getItem(3).addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                final int[] start = {0};
                final int[] end = {0};
                final boolean[] isReplace = {false};
                final String[] texts = {""};
                Dialog dialog = new Dialog(frame, "查找", false);
                dialog.setLayout(new FlowLayout());
                dialog.setBounds(400, 300, 300, 150);
                Label Find = new Label("查找内容");
                TextField FindText = new TextField(20);
                Label ReplaceWith = new Label("替 换 为");
                TextField ReplaceText = new TextField(20);
                Button Next = new Button("下一个");
                Button Replace = new Button("替换");
                Button Cancel = new Button("取消");
                dialog.add(Find);
                dialog.add(FindText);
                dialog.add(ReplaceWith);
                dialog.add(ReplaceText);
                dialog.add(Next);
                dialog.add(Replace);
                dialog.add(Cancel);
                dialog.setVisible(true);
                dialog.addWindowListener(new WindowAdapter() {
                    @Override
                    public void windowClosing(WindowEvent e) {
                        dialog.dispose();
                    }
                });
                Next.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        if (end[0] >= 0) {
                            isReplace[0] = true;
                            String fileset = FindText.getText();
                            String TextAll = textArea.getText();
                            int x = TextAll.indexOf(fileset, start[0]);
                            int n = x + fileset.length();
                            end[0] = x;
                            textArea.select(end[0], n);
                            System.out.println(end[0] + "--" + n);
                            start[0] = n;
                        }
                    }
                });
                Replace.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        if (isReplace[0] && end[0] >= 0 && start[0] > 0) {
                            isReplace[0] = false;
                            textArea.replaceRange("", end[0], start[0]);
                            textArea.insert(ReplaceText.getText(), end[0]);
                        }
                    }
                });

                dialog.addWindowListener(new WindowAdapter() {
                    @Override
                    public void windowActivated(WindowEvent e) {
                        texts[0] = textArea.getText();
                    }
                });

                Cancel.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        textArea.setText(texts[0]);
                        dialog.dispose();
                    }
                });
            }
        });

        menus[2].getItem(0).addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new Thread(() -> {
                    String cmd = "cmd.exe /c start ";

                    String file = "https://www.bing.com/";
                    try {
                        Runtime.getRuntime().exec(cmd + file);
                    } catch (IOException ignore) {
                        ignore.printStackTrace();
                    }
                }).start();
            }
        });
    }
}
