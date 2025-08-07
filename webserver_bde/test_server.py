import socket
import threading
import time

HOSTS = ['127.0.0.1']  # Add as many hosts as you want
PORTS = [8080, 8000, 3030]
CLIENTS_PER_PORT = 3

def client_thread(host, port, client_id):
    try:
        with socket.create_connection((host, port), timeout=5) as s:
            print(f"[{host}:{port}] Client {client_id} connected")

                        # Send "hello"
            s.sendall(b"hello\n")
            response = s.recv(1024)
            print(f"[{host}:{port}] Client {client_id} received: {response.decode().strip()}")

            # Example: send/receive data here if needed
            time.sleep(1)  # Keep connection alive for a bit
    except Exception as e:
        print(f"[{host}:{port}] Client {client_id} failed to connect: {e}")

threads = []

for host in HOSTS:
    for port in PORTS:
        for client_id in range(1, CLIENTS_PER_PORT + 1):
            t = threading.Thread(target=client_thread, args=(host, port, client_id))
            t.start()
            threads.append(t)

for t in threads:
    t.join()

print("All clients done.")

