import qrcode

# Generate QR code
img = qrcode.make("https://youtu.be/dQw4w9WgXcQ")

# Save as file
img.save("qr.png", "PNG")
img.show()
