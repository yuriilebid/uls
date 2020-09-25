<h1>My re-implementation of unix <b>ls</b> utility</h1>
<p>For details about ls - <a href="https://en.wikipedia.org/wiki/Ls">Wiki</a><p>
 <p><b>Syntax:</b> ./uls [-flag (optional)] [directory_name1, ..., directory_nameX (optional, if no directory specified, current working directory is taken)]</p>
<p>Features implemented:<p>
<ul>
  <li><b>-a</b> flag - show all directories (also hidden - those, which start with dot)</li> 
  <li><b>-A</b> flag - show all directories, except . and ..</li>
  <li><b>-R</b> flag - recursively lists the content of cwd and all subdirictories.</li>
  <li><b>-m</b> flag - list the content of directory in comma separated style.</li>
  <li><b>-p</b> flag - Write a slash (`/') after each filename if that file is a directory.</li>
  <li><b>-1</b> flag - Force output to be one entry per line. This is the default when output is not to a terminal.</li>
  <li><b>-C</b> flag - Force multi-column output; this is the default when output is to a terminal.</li>
  <li><b>-o</b> flag - List in long format, but omit the group id.</li>
  <li><b>-g</b> flag - it is used to display the group name in the long (-l) format output  (the owner name is suppressed).</li>
  <li><b>-d</b> flag - Directories are listed as plain files (not searched recursively).</li>
</ul>

<h2>Compilation</h2>
<ul> 
 <li>To <b>compile</b> write <i><b>`make`</b></i> in root directory.</li>
 <li>Compilation was done on <b>MacOS</b>. Other <b>OS</b> were not tested.</li>
</ul>


<h3>Overview</h3>

![ezgif com-video-to-gif (1)](https://user-images.githubusercontent.com/11888485/92944562-cf481e00-f45c-11ea-8eff-ac21da5d8350.gif)

