int main(int argc, char const *argv[]) {
#ifdef UNIX
  return 1;
#elif WIN32
  return 0;
#endif
}
