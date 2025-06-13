from PIL import Image, ImageDraw

def determine_region(x, y):
    if (x < 10 and y < 11): return 1

    if (x >= 10 and y < 8): return 2

    return 3

def determine_terrain(x, y):
    if (x == 4 and y == 7) or (x == 25 and y == 3) or (x == 17 and y == 13): return "City"

    if (9 <= x and x <= 11) and (11 <= y and y <= 13): return "Forests"

    if (19 <= x and x <= 25) and (9 <= y and y <= 11): return "Deserts"

    if (12 <= x and x <= 17) and (2 <= y and y <= 5): return "Mountains"

    if (0 <= x and x <= 10) and (10 <= y): return "Sea"

    if (x == 9) and (7 <= y and y <= 10): return "River"

    return "Plains"

def determine_color(string):
    if string == "City": return (220, 220, 220, 127)
    if string == "Forests": return (0, 255, 0, 127)
    if string == "Deserts": return (255, 255, 0, 127)
    if string == "Mountains": return (180, 180, 180, 127)
    if string == "Sea": return (0, 0, 255, 127)
    if string == "River": return (0, 0, 220, 127)
    return (100, 200, 100, 127)


img = Image.open("assets/maps/test/map3v3.png")
draw = ImageDraw.Draw(img) 

with open("assets/maps/test/tmp.json", "w") as f:
    f.write("[")
    for i in range(15):
        f.write("[")
        for j in range(27):
            draw.line((j * 30,0, j * 30,460), fill=128)
            draw.rectangle(((j*30, i*30), (j*30+30, i*30+30)), fill=determine_color(determine_terrain(j, i)))
            f.write("""{{
    "region_id": {},
    "terrain": "{}"
}}""".format(determine_region(j, i), determine_terrain(j, i)))
            draw.text(
                (j*30, i*30),
                str(determine_region(j,i)),
                (0, 0, 0)
            )
            if j != 26: f.write(",")
        f.write("]")
        draw.line((0, i * 30, 819,i * 30), fill=128)
        if i != 14: f.write(",")
    f.write("]")

img.show()
