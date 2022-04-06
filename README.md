# Qubitro_LoRa_Gateway
Using LoRa 868 modules on M5Stack Core units to send remote GPS and environment data to the Qubitro portal.

Continuing on from my last video "M5Stack UIFlow and Qubitro IoT Platform: Getting Started" nobody busted me over the fact that I didn't do anything with the LoRa 868 modules. So now I need to complete my project by implementing LoRa communication between two M5Stack Core IoT units and transmit data to the Qubitro portal.

I am keenly interested in the map widget for my Qubitro dashboard. I want to see how this works. We can see this map widget on the Qubitro portal is very useful. The pin follows me on the map as I walk around the park.
In the device analysis I have made these two charts. I grouped the pressure and altitude data on one chart. In the other chart I grouped temperature and humidity.

Another cool feature on the Qubitro portal is the ability to export the data you have collected. You can download it in the form of a JSON file. I found this online JSON to CSV converter. https://data.page/json/csv

Paste or upload your JSON data at the top and you can download the CSV below.

Here I have cleaned the CSV file up a bit and plugged it into https://www.gpsvisualizer.com/. Yeah I had to do a bit of walking just to make this video. It's all recorded on the Qubitro portal.

This was a fun experience for me. Qubitro really made this project easy to connect and visualize the data. Check out Qubitro for yourself here: 
https://qubitro.com/

IoT Playlist on ShotokuTech: Exploring IoT one step at a time.
https://www.youtube.com/playlist?list=PLVPBipeObwMN3WIwFWOQ2esviKvBcS7Qb

Open in UIFlow:
https://flow.m5stack.com/

I Made a LoRa Gateway for Qubitro with M5Stack UIFlow https://youtu.be/yyrZrP6KDZs
