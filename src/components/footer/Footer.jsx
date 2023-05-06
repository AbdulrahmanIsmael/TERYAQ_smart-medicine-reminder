function Footer() {
  const currentYear = new Date().getFullYear();

  return (
    <footer>
      <a href='https:engfac.mans.edu.eg/en/mathematics-and-engineering-physics-department-25'>
        ECE{' '}
      </a>
      <p>© {currentYear}</p>
    </footer>
  );
}
export default Footer;
