#include <stdio.h>
#include <string.h>

char tracks[][80] = {
  "I left my heart in Harvard Med School",
  "Newark, Newark - a wonderful town",
  "Dancing with a Dork",
  "From here to maternity",
  "The girl from Iwo Jima",
};

void find_track(char search_for[])
{
  int i;
  for (i = 0; i < 5; i++) {
    if (strstr(tracks[i], search_for))
      printf("Track %i: '%s'\n", i, tracks[i]);
  }
}

int main()
{
  char search_for[80];
  printf("Search for: ");
  scanf("%79s", search_for); // This one stops at spaces
  //fgets(search_for, sizeof(search_for), stdin); // this one can read spaces too
  printf("%s\n", search_for);
  search_for[strlen(search_for) - 1] = '\0';
  find_track(search_for);
  return 0;
}
