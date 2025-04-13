# Hello 42 Visitor 👋

If you’ve stumbled upon this repo, you're probably curious how someone else built their `so_long` project.  
To be honest — I don’t think I did that great on this one, especially after finishing Common Core and realizing all the things I could’ve done better 😅

Will I rework it? Who knows. If I do, the repo will get updated, but not *this* commit. So enjoy this snapshot in time! 🤣

---

## 🚀 What's Actually Helpful Here

This repo includes a `Dockerfile` and a `docker-compose.yml` — and that’s the part that might really help you.

At school, the 42 workstation is the easiest way to build your `so_long` project with already installed `minilibx`.  
But if you're working on your **own computer** (especially on **macOS**), setting that up can be a pain.

This setup will:
- Spin up a Linux container with everything pre-installed
- Give you the similar dev environment as 42's computers (change the image to ubuntu if you prefer)
- Let you run GUI apps from inside the container, like `so_long` and `xeyes` with your mac

---

## 💻 Requirements (on your host machine)

Before you begin, make sure you have:

- ✅ [Docker](https://www.docker.com/products/docker-desktop/)
- ✅ [XQuartz](https://www.xquartz.org/) (for GUI display on macOS)

---

## 🛠️ Getting Started

Run the dev environment with:

```bash
./start_dev.sh
```

This script will:

- Build the Docker container
- Start it using docker-compose
- Automatically enter the container shell at /home/program

Now you're ready to make and run your project from inside the container. 🎮

---

## 🖼️ GUI Setup

To get graphical output like your game window or xeyes, follow these steps:

1. Start XQuartz:
```terminal
open -a XQuartz
```

2. Enable network connections (first time only)
In XQuartz → Preferences → Security → ✅ Allow connections from network clients
Then restart XQuartz.

3. Test the connection  
Inside your container: 
```sh 
apk add xeyes 
xeyes
```
If xeyes opens a window — you're golden 🌟

## 📁 Project Structure
This repo uses a bind mount (./program:/home/program), which means:

Any code you edit in your ./program folder on your host is immediately reflected inside the container.

You get to use VS Code on your Mac, while compiling and running inside Linux. Best of both worlds.

## 🧹 Clean Up

When you’re done working on this project:
```bash
./cleanup.sh
```

This will:

- Revoke X11 permissions (xhost -)
- Stop and remove the Docker container and network

⚠️ Note: You don’t need to run this every time — only when you're truly done.
Otherwise, you’ll have to rebuild the container again next time.

## 🧠 Final Notes

This setup isn’t perfect,but may help you working on so_long outside of 42 campus. Have fun exploring new way to work your code in the container 🥳