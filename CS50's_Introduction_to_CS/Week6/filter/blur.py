from PIL import Image, ImageFilter

before = Image.open("bridge.bmp")
after = before.filter(ImageFilter.BoxBlur(1))
later = before.filter(ImageFilter.BoxBlur(10))
after.save("less_blur.bmp")
later.save("more_blur.bmp")
