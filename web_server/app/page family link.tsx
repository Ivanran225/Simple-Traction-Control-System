import Image from 'next/image'

export default function ondas() {
  return (
    <div>
      <header className="bg-purple-700 py-6 px-6 flex items-center justify-between">
        <div className="flex">
          <Image
            src="/Familylink_Simple-removebg-preview.png"
            alt="Picture of the author"
            width={40}
            height={40}
          />
        </div>
        <nav>
          <a href="/PanelDeActividades" className="text-gray-300 text-xl font-thin hover:text-white hover:underline mx-4">Actividades</a>
          <a href="#" className="text-gray-300 text-xl font-thin hover:text-white hover:underline mx-4">Contactos</a>
          <a href="#" className="text-gray-300 text-xl font-thin hover:text-white hover:underline mx-4">Informacion</a>
          <a href="#" className="text-gray-300 text-xl font-thin hover:text-white hover:underline mx-4">Equipo</a>
          <a href="/logIn" className="bg-transparent hover:bg-blue-500 text-white text-xl font-thin hover:text-white py-2 px-4 border border-blue-500 hover:border-transparent rounded">Iniciar sesion</a>
          <a href="/NewAccounts" className="ml-4 text-xl bg-blue-500 hover:bg-blue-600 text-white font-thin px-4 py-2 rounded">Registrarse</a>
        </nav>
      </header>

      <main className="relative mx-auto">
        <div className="relative">
          <svg
            className="absolute top-0 left-0 z-10"
            viewBox="0 0 1366 209" fill="none" xmlns="http://www.w3.org/2000/svg">
        <path d="M1364 0H-2V72.6316H1364V0Z" fill="#7E22CE"/>
        <path d="M1364 46.4036H956V127.105H1364V46.4036Z" fill="#7E22CE"/>
        <path d="M552 31.272H329V111.974H552V31.272Z" fill="#7E22CE"/>
        <path d="M73 31.272H-2V111.974H73V31.272Z" fill="#7E22CE"/>
        <path d="M-116 190.971C-116 190.971 100.87 84.8151 190.501 76.4756C298.712 66.4081 353.52 144.484 462 138.011C570.751 131.521 628.361 78.2571 736.5 64.9534C914.667 43.0359 1010 217.198 1171 170.291C1223.65 154.95 1286.69 119.427 1341.5 119.427C1414.5 119.427 1599.68 88.0765 1599.68 88.0765" stroke="#85DFF3" strokeWidth="38"/>
        <path d="M-66 159.246C-66 159.246 76.9074 51.0221 171.333 43.6339C285.334 34.7139 341.799 109.738 456.028 104.257C570.54 98.7623 636.526 43.7898 750.5 31.7764C935.5 22.6974 992.769 205.661 1167 137.585C1224.5 115.118 1305 75.041 1366 75.041C1451.72 75.041 1576.68 43.6339 1576.68 43.6339" stroke="#4151DA" strokeWidth="53"/>
        </svg>

  
  <div className="w-full h-[500px] md:h-[600px] lg:h-[700px] xl:h-[800px] bg-cover bg-center"
        style={{ backgroundImage: "url('/Imagen_Landing1.jpg')" }}>
          
          <div className="relative z-30 flex flex-col justify-center items-center h-full -left-1/4">
  <h5 className="text-6xl font-bold text-black">
    Familylink
  </h5>
  <p className="text-4xl font-bold text-black mt-3">
    En busca del bienestar familiar
  </p>
      </div>  
        </div>
      </div>
      <section className="py-36 px-36">
          <div className="container">
            <p className="text-black text-5xl font-thin ">Sobre Nosotros...</p>
            <br />
            <p className="text-blue-600 text-3xl font-thin">Buscamos mejorar la comunicacion de forma que no hallan problemas a la hora de realizar tareas y de esta forma ayudar a personas mayores en diversas áreas de su vida. La aplicación tiene varias funciones útiles, como recordatorios de tareas y actividades diarias, así como la capacidad de facilitar la comunicación con contactos de emergencia, amigos, familiares y conocidos, lo que proporciona una mayor seguridad para el usuario en caso de necesidad.</p>
          </div>
        </section>
      <div className="relative">
      <svg className="absolute left-0 top-0 -z-10"
          width="1366" height="2547" viewBox="0 0 1366 2547" fill="none" xmlns="http://www.w3.org/2000/svg">
          <rect width="1385" height="166" transform="matrix(1 0 0 -1 10 388.6)" fill="#7E22CE"/>
          <path d="M-82.9116 52.0198C-82.9116 52.0198 133.958 157.253 223.589 165.519C331.8 175.5 386.608 98.1029 495.088 104.52C603.839 110.953 662.626 161.833 770.765 175.02C948.932 196.747 1043.09 26.0203 1204.09 72.5199C1256.74 87.7279 1321.28 154.02 1376.09 154.02C1449.09 154.02 1632.77 154.02 1632.77 154.02" stroke="#85DFF3" strokeWidth="49"/>
          <path d="M-78.0178 185.869C-78.0178 185.869 61.0529 259.482 159.714 269.772C278.827 282.196 340.007 206.016 459.454 214.882C579.197 223.769 611.262 260.357 730.263 275.987C926.325 301.738 1032.71 128.501 1222.77 175.02C1344.77 204.882 1340.42 248.708 1399.09 261.02C1480.09 278.02 1586.93 298.992 1586.93 298.992" stroke="#7E22CE" strokeWidth="115"/>
          <path d="M-42.8638 103.183C-42.8638 103.183 103.442 207.635 200.113 214.766C316.825 223.375 374.632 150.966 491.578 156.256C608.813 161.559 670.407 222.539 787.091 234.135C979.338 253.239 1038.53 64.2542 1216.9 129.958C1271.37 150.021 1354.6 189.348 1417.05 189.348C1504.81 189.348 1638.88 214.766 1638.88 214.766" stroke="#4151DA" strokeWidth="66"/>
          <path d="M0 276L300.997 276H484.551L530.624 276H584.421L634.103 276H735.426H802.659H859.548L975.396 276H1094.35L1256.22 276L1385 276V2547H0V276Z" fill="#7E22CE"/>
        </svg>
        <div className="z-10">
        <section className="py-96 px-36">
          <p className=" text-black text-5xl font-thin py-12">Como funciona?</p><br />
          <div className="flex">
            <br />
            <p className="shrink text-white text-3xl font-thin px-16 ">En primer lugar, los dos usuarios deberian estar conectados a una cuenta de Familylink. Despues de tener las dos cuentas creadas, el usuario (familiar, conocido, entre otr@s) tendrá que crear una lista de actividades nueva, en la cual el medico, cuidador, etc, van a unirse ingresando el nombre de la lista de actividades y una contraseña.  </p>
            <svg className="shrink-0"
              width="221" height="256" viewBox="0 0 221 256" fill="none" xmlns="http://www.w3.org/2000/svg">
              <g clipPath="url(#clip0_0_1)">
              <path d="M147.812 44.2319C151.376 44.2319 154.794 45.4945 157.314 47.742C159.834 49.9896 161.25 53.0379 161.25 56.2164V200.031C161.25 203.209 159.834 206.258 157.314 208.505C154.794 210.753 151.376 212.015 147.812 212.015H67.1875C63.6237 212.015 60.2058 210.753 57.6858 208.505C55.1657 206.258 53.75 203.209 53.75 200.031V56.2164C53.75 53.0379 55.1657 49.9896 57.6858 47.742C60.2058 45.4945 63.6237 44.2319 67.1875 44.2319H147.812ZM67.1875 32.2473C60.0598 32.2473 53.224 34.7726 48.184 39.2677C43.144 43.7628 40.3125 49.8594 40.3125 56.2164V200.031C40.3125 206.388 43.144 212.484 48.184 216.98C53.224 221.475 60.0598 224 67.1875 224H147.812C154.94 224 161.776 221.475 166.816 216.98C171.856 212.484 174.688 206.388 174.688 200.031V56.2164C174.688 49.8594 171.856 43.7628 166.816 39.2677C161.776 34.7726 154.94 32.2473 147.812 32.2473H67.1875Z" fill="black"/>
              <path d="M107.5 200.031C111.064 200.031 114.482 198.768 117.002 196.521C119.522 194.273 120.938 191.225 120.938 188.046C120.938 184.868 119.522 181.819 117.002 179.572C114.482 177.324 111.064 176.062 107.5 176.062C103.936 176.062 100.518 177.324 97.9983 179.572C95.4782 181.819 94.0625 184.868 94.0625 188.046C94.0625 191.225 95.4782 194.273 97.9983 196.521C100.518 198.768 103.936 200.031 107.5 200.031Z" fill="black"/>
              <g clipPath="url(#clip1_0_1)">
              <path d="M155.812 44.2319C159.376 44.2319 162.794 45.4945 165.314 47.742C167.834 49.9896 169.25 53.0379 169.25 56.2164V200.031C169.25 203.209 167.834 206.258 165.314 208.505C162.794 210.753 159.376 212.015 155.812 212.015H75.1875C71.6237 212.015 68.2058 210.753 65.6858 208.505C63.1657 206.258 61.75 203.209 61.75 200.031V56.2164C61.75 53.0379 63.1657 49.9896 65.6858 47.742C68.2058 45.4945 71.6237 44.2319 75.1875 44.2319H155.812ZM75.1875 32.2473C68.0598 32.2473 61.224 34.7726 56.184 39.2677C51.144 43.7628 48.3125 49.8594 48.3125 56.2164V200.031C48.3125 206.388 51.144 212.484 56.184 216.98C61.224 221.475 68.0598 224 75.1875 224H155.812C162.94 224 169.776 221.475 174.816 216.98C179.856 212.484 182.688 206.388 182.688 200.031V56.2164C182.688 49.8594 179.856 43.7628 174.816 39.2677C169.776 34.7726 162.94 32.2473 155.812 32.2473H75.1875Z" fill="white"/>
              <path d="M115.5 200.031C119.064 200.031 122.482 198.768 125.002 196.521C127.522 194.273 128.938 191.225 128.938 188.046C128.938 184.868 127.522 181.819 125.002 179.572C122.482 177.324 119.064 176.062 115.5 176.062C111.936 176.062 108.518 177.324 105.998 179.572C103.478 181.819 102.062 184.868 102.062 188.046C102.062 191.225 103.478 194.273 105.998 196.521C108.518 198.768 111.936 200.031 115.5 200.031Z" fill="white"/>
              </g>
              </g>
              <path d="M57.4166 23.3194L54.4221 23.1389L51.3673 23.9566L52.8114 9.2946e-05L58.8005 0.361112L57.4166 23.3194Z" fill="white"/>
              <path d="M32.3174 40.8408L31.1387 43.7752L30.9582 46.7698L7.99985 45.3859L8.36087 39.3967L32.3174 40.8408Z" fill="white"/>
              <path d="M42.0977 28.1638L39.0283 29.2237L37.6074 32.1435L22.352 14.9309L26.8422 10.9513L42.0977 28.1638Z" fill="white"/>
              <path d="M173 233H176L179 232V256H173V233Z" fill="white"/>
              <path d="M197 214L198 211V208H221V214H197Z" fill="white"/>
              <path d="M188 227.243L191 226L192.243 223L208.506 239.263L204.263 243.506L188 227.243Z" fill="white"/>
              <defs>
              <clipPath id="clip0_0_1">
              <rect width="210" height="200" fill="white" transform="translate(0 24)"/>
              </clipPath>
              <clipPath id="clip1_0_1">
              <rect width="210" height="200" fill="white" transform="translate(8 24)"/>
              </clipPath>
              </defs>
            </svg>

          </div>
        </section>
        <section className="-top-36">
          <div className="flex">
            <svg className="shrink-0"
        width="246" height="228" viewBox="0 0 246 228" fill="none" xmlns="http://www.w3.org/2000/svg">
          <path d="M29.4667 45.5628L70.7109 63.5427C81.9472 68.441 90.5973 77.6382 94.6483 88.9939V88.9939C100.557 105.557 116.009 117.016 133.97 118.155L145.71 118.899C158.638 119.718 170.641 125.573 179.028 135.151L198.575 157.471" stroke="black" strokeWidth="18"/>
          <path d="M38.6984 40.3581L80.694 63.4405C89.574 68.3213 97.3018 74.9603 103.388 82.9369L105.441 85.6285C114.267 97.1967 126.481 105.868 140.49 110.512L165.021 118.643C169.102 119.996 173.008 121.802 176.661 124.027L212.614 145.92" stroke="black" strokeWidth="18"/>
          <path d="M38.6984 40.3581L80.694 63.4405C89.574 68.3213 97.3018 74.9603 103.388 82.9369L105.441 85.6285C114.267 97.1967 126.481 105.868 140.49 110.512L165.021 118.643C169.102 119.996 173.008 121.802 176.661 124.027L212.614 145.92" stroke="black" strokeWidth="18"/>
          <path d="M38.6984 40.3581L80.694 63.4405C89.574 68.3213 97.3018 74.9603 103.388 82.9369L105.441 85.6285C114.267 97.1967 126.481 105.868 140.49 110.512L165.021 118.643C169.102 119.996 173.008 121.802 176.661 124.027L212.614 145.92" stroke="white" strokeWidth="18"/>
          <path d="M47.4422 39.3302L93.6119 57.7829C103.894 61.8922 112.696 68.8535 118.942 77.8134V77.8134C126.239 88.2827 136.994 95.9773 149.434 99.6284L161.315 103.116C171.568 106.125 180.707 111.924 187.668 119.839L212.614 148.2" stroke="black" strokeWidth="18"/>
          <path d="M20.5 199.5C17.5959 199.5 15.1598 198.588 13.1918 196.764C11.2238 194.94 10.2432 192.685 10.25 190C10.25 187.308 11.234 185.051 13.202 183.227C15.17 181.403 17.6027 180.494 20.5 180.5H225.5C228.404 180.5 230.84 181.412 232.808 183.236C234.776 185.06 235.757 187.315 235.75 190C235.75 192.692 234.766 194.95 232.798 196.774C230.83 198.598 228.397 199.506 225.5 199.5H20.5ZM41 171C35.3625 171 30.5348 169.138 26.5168 165.414C22.4988 161.69 20.4932 157.219 20.5 152V47.5C20.5 42.275 22.509 37.8005 26.527 34.0765C30.545 30.3525 35.3694 28.4937 41 28.5H205C210.638 28.5 215.465 30.362 219.483 34.086C223.501 37.81 225.507 42.2813 225.5 47.5V152C225.5 157.225 223.491 161.7 219.473 165.424C215.455 169.148 210.631 171.006 205 171H41ZM41 152H205V47.5H41V152Z" fill="white"/>
        </svg>

        <p className="shrink text-black text-3xl font-thin">Ya con los distintos usuarios adentro de la pagina de la lista, el usuario líder o  creador de la lista podra generar y escribir distintas actividades , agregar informacion medicinal, (ejemplo: tomar tal pastilla a la hora --:--). u otras notas que se le puedan agregar al panel. Estas notas se pueden modificar en cualquier momento.</p>

          </div>
        
        </section>      
        <section className="py-16">
          <div className="container mx-auto">
            <p className="text-black text-5xl font-thin">Ejemplos de uso</p>
            <div className="grid grid-cols-3 gap-8">
              <div className="testimonial-item bg-white p-6 rounded-lg shadow-md">
                <p className="mb-4">"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam at purus est. Curabitur quis mi et tortor ultricies tincidunt."</p>
                <h4 className="text-lg font-bold">John Doe</h4>
                <p className="text-gray-500">CEO, Company</p>
              </div>
              <div className="testimonial-item bg-white p-6 rounded-lg shadow-md">
                <p className="mb-4">"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam at purus est. Curabitur quis mi et tortor ultricies tincidunt."</p>
                <h4 className="text-lg font-bold">Jane Doe</h4>
                <p className="text-gray-500">CTO, Company</p>
              </div>
              <div className="testimonial-item bg-white p-6 rounded-lg shadow-md">
                <p className="mb-4">"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam at purus est. Curabitur quis mi et tortor ultricies tincidunt."</p>
                <h4 className="text-lg font-bold">Bob Smith</h4>
                <p className="text-gray-500">Marketing Director, Company</p>
              </div>
            </div>
          </div>
        </section>
        </div>
        </div>
      </main>

      <footer className="bg-gray-900 text-white py-4 px-6">
        <div className="container mx-auto flex items-center justify-between">
          <div className="footer-logo">
            <h1 className="text-xl font-bold">Logo</h1>
          </div>
          <nav className="footer-links">
            <a href="#" className="text-gray-300 hover:text-white mx-4">Home</a>
            <a href="#" className="text-gray-300 hover:text-white mx-4">Features</a>
            <a href="#" className="text-gray-300 hover:text-white mx-4">About</a>
            <a href="#" className="text-gray-300 hover:text-white mx-4">Contact</a>
          </nav>
        </div>
      </footer>
    </div>
  )
}
