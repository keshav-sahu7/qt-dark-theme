# QT DarkTheme

A beautiful dark theme for Qt applications. The dark theme is available in different flavours/colors. It is available in purple, green, maroon and blue colors. But we can also use custom colors.

All themes uses two main colors PRIMARY COLOR and SECONDARY COLOR. PRIMARY COLOR is used for all the border colors, background colors for buttons, header colors in normal modes / active mode. SECONDARY COLOR is used in case of mouse hover, keyboard focus, item is selected, and button press.

## Quick Links

- For using in your project look at [Usage](#usage)
- For creating custom themes look at [Dark theme with custom colors](#dark-theme-with-custom-colors)

Have a look at here

![all dark themes](screenshots/all-themes.gif?raw=true "Title")

## Dark Purple

It uses rgb( 121, 80, 245) as primary color and rgb( 89, 38, 242) as secondary color.

![dark purple theme](screenshots/purple.PNG?raw=true "Title")

## Dark Maroon

It uses rgb( 195, 33, 72) as primary color and rgb( 171, 29, 63) as secondary color.

![dark maroon theme](screenshots/maroon.PNG?raw=true "Title")

## Dark Green

It uses rgb( 31, 163, 70) as primary color and rgb( 24, 124, 54) as secondary color.

![dark green theme](screenshots/green.PNG?raw=true "Title")

## Dark Blue

It uses rgb( 34, 34, 255) as primary color and rgb( 0, 0, 223) as secondary color.

![dark blue theme](screenshots/blue.PNG?raw=true "Title")

## Menu and Menu Items

Menu will look like this

![menu](screenshots/menu.png?raw=true "Title")

## Disabled Mode

When in disabled mode it will look same in any of the given dark themes.

![disabled mode](screenshots/disabled-mode.PNG?raw=true "Title")

## Default Look

When no theme is applied it looks like this
![default look](screenshots/default.PNG?raw=true "Title")

## Usage

Add [icons](icons) directory and .qss files to your Qt resource files (qrc files e.g. resource.qrc).
Then in your main source file (C++) use

```cpp

QApplication app(argc, argv);

// other codes here!

QString theme = "DarkMaroon"; // it can be DarkBlue, DarkPurple, or DarkGreen

QFile theme_file(QString(":/%1.qss").arg(theme));
theme_file.open(QFile::ReadOnly);   //open theme file

if(theme_file.isOpen())
{
    app.setStyleSheet(theme_file.readAll());        //set the theme here!
    theme_file.close();
}
else
{
    qDebug("File couldn't be opened!");
}

```

For using in python project use

```python
try:
    theme = "DarkMaroon" # it can be DarkBlue, DarkPurple, or DarkGreen too.
    with open(":/{}.qss".format(theme),"r") as theme_file:
        # app is a QApplication instance.
        app.setStyleTheme(theme_file.read())
except:
    print("error : couldn't open the file.")

```

## Dark Theme With Custom Colors

Recreating the theme with custom colors is farely easy. Just open a text editor and do as mentioned below:

- Open template.qss file in any text editor.
- Replace word `PRIMARY_COLOR` with your favourite color's rgb value. For example, `110, 202, 230`.
- Replace word `SECONDARY_COLOR` with a darker color's rgb value. For example, `90, 202, 230`.
- Copy any of the directory from the [icons](icons) and replace or recreate every icon. Normal icons should be in PRIMARY_COLOR while icons ending with _hover should be in SECONDARY_COLOR. Only alter the colored icons and leave other disabled and white icons.
- Now replace word `ICON_PATH` with the path/url of your icon. For example `:/images/`.

`Alert`: PRIMARY_COLOR and SECONDARY_COLOR must follow this specific rule `R, G, B` value of r, g, and b and two comma in between. R, G, and B can be a number ranging from 0 to 255 or may be percentage of the colors.
