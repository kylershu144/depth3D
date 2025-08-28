import torch

def main():
    print("Hello from depth3d!")
    print(torch.cuda.is_available())
    print(torch.version.cuda)


if __name__ == "__main__":
    main()
